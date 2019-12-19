import pygame
import sys
from ctlClass import Speaker, Option
from crimeScene import LoadScene
import time
# 游戏资源存储
pic_bg = ''
pic_art = {}
article = []
event = {}
sentence = {}
PC = 0  # 处理的语句在article中的位置

def LoadText(i):
    """
    读取剧本文件
    i代表章节的序号
    """
    global article, PC
    article = []
    PC = 0
    with open(u"./text/Chapter"+str(i)+".txt", encoding='UTF-8') as data:
        for line in data.readlines():
            if line == '\n':
                continue
            article.append(str(line).strip())
    Music(i).play()


def AnalyText():
    """
    根据不同指令行携带的不同信息进行相应预处理与预存储
    """
    global pic_bg, pic_art, sentence
    num = -1  # 记录行数
    pic_bg = ''
    pic_art = {}
    sentence = {}
    for col in article:
        num = num + 1
        col = col.split(' ')
        if col[0] == 'background':
            pic_bg = col[2][1:-3]
        if col[0] == 'character':
            pic_art[col[1]] = col[3][1:-3]
        if col[0] == 'event':
            b = col[3][:-2]
            if b == 'true':
                event[col[1]] = True
            elif b == 'false':
                event[col[1]] = False
        if '9' >= col[0][0] >= '1':
            sentence[int(col[0])] = num


def LoadInstr():
    """
    取一条文本指令
    :return: 经过空格分隔后的句子元素列表
    """
    global PC
    i = article[PC]
    i = i.split(' ')
    PC += 1
    return i


R_name = ['' for i in range(3)]
R_bool = [True for i in range(3)]
OPTION = {}

def ParseInstr():
    """
    分析指令函数：判断指令是对话还是功能指令，功能指令则执行器操作，对话指令返回内容进行显示
    :return: 四个变量分别为左中右需要显示的人物图片，及对话内容
    """
    global R_bool, R_name, PC, i, OPTION
    if PC >= len(article) - 1:
        Speaker('null', False, 'null', False, 'null', False, '本章已完结……')
        time.sleep(3)
        i = i + 1
        if i > 3:
            Speaker('null', False, 'null', False, 'null', False, "全剧完")
            sys.exit()
        LoadText(i)  # 加载文本
        AnalyText()  # 处理文本
    while PC < len(article):
        ins = LoadInstr()  # 取一条指令
        if ins[0] == 'set':  # 功能扩展
            if ins[1] == 'position':  # 设置人物的显示
                for k in range(2, 5):
                    R_name[k - 2] = ins[k]
                    if ins[k] == 'null':
                        R_bool[k-2] = False
                    else:
                        R_bool[k-2] = True
        elif ins[0] == 'options':  # 选择项
            OPTION = {}
            R_name = ['null' for i in range(3)]
            R_bool = [False for i in range(3)]
            # 开始读取case指令获取选项与跳转的关系
            for i in range(4):  # 假设最多只有四个选项
                t_ins = LoadInstr()
                if t_ins[0] == 'case':
                    OPTION[int(t_ins[1][0])] = int(t_ins[3][:-1])
                else:
                    break
            return ins[1][:-1]

        elif '1' <= ins[0][0] <= '9':
            return ins[1] + ':' + ins[3][1:-2]  # 只有遇到说话内容的时候才返回



# 初始化
i = 1
LoadText(i)
AnalyText()
# 控制流程
while True:  # 无限循环直至用户点击×
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # 用户按下了结束键
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:

            # 用户点击箭头切换场景
            px, py = event.pos
            if (920 <= px <= 978) and (22 <= py <= 55):
                LoadScene()            #切换场景到案发现场

            t = ParseInstr()
            n = R_name
            b = R_bool
            Speaker(n[0], b[0], n[1], b[1], n[2], b[2], t)
        elif event.type == pygame.KEYDOWN:
            choice = Option(event.key)
            PC = sentence[int(OPTION[choice])]
            t = ParseInstr()
            n = R_name
            b = R_bool
            Speaker(n[0], b[0], n[1], b[1], n[2], b[2], t)
    pygame.display.update()  # 显示图片
