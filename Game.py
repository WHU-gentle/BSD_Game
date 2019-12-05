import os
import pygame
import io
import time
from ctlClass import *

# 游戏资源存储
<<<<<<< HEAD
pic_bg = []
=======
pic_bg = ''
>>>>>>> c53c86c00b5b7b581fa88f6774f51bdbbe5131c6
pic_art = {}
article = []
event = {}
sentence = {}
PC = 0  # 处理的语句在article中的位置

# 读取结构化剧本文件
with open(u"./text/Chapter1.txt", encoding='UTF-8') as data:
    for line in data.readlines():
        if line == '\n':
            continue
        article.append(str(line).strip())

num = -1  # 记录行数
for col in article:
    num = num + 1
    col = col.split(' ')
    if col[0] == 'background':
<<<<<<< HEAD
        pic_bg.append(col[2][1:-3])
=======
        pic_bg = col[2][1:-3]
>>>>>>> c53c86c00b5b7b581fa88f6774f51bdbbe5131c6
    if col[0] == 'character':
        pic_art[col[1]] = col[3][1:-3]
    if col[0] == 'event':
        b = col[3][:-2]
        if b == 'true':
            event[col[1]] = True
        elif b == 'false':
            event[col[1]] = False
    if '9' >= col[0][0] >= '1':
        sentence[col[0]] = num


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


def ParseInstr():
    """
    分析指令函数：判断指令是对话还是功能指令，功能指令则执行器操作，对话指令返回内容进行显示
    :return: 四个变量分别为左中右需要显示的人物图片，及对话内容
    """
    global R_bool, R_name
    while PC < len(article):
        ins = LoadInstr()  # 取一条指令
        if ins[0] == 'set':  # 功能扩展
            if ins[1] == 'position':  # 设置人物的显示
                for k in range(2, 5):
                    if ins[k] == 'null':
                        R_name[k-2] = ''
                        R_bool[k-2] = False
                    else:
                        R_name[k-2] = ins[k]
                        R_bool[k-2] = True
        elif '1' <= ins[0][0] <= '9':
            return ins[3][1:-3]  # 只有遇到说话内容的时候才返回


# 控制流程
while True:  # 无限循环直至用户点击×
    if PC >= len(article):
        Speaker('', False, '', False, '', False, "本章已完结……")
        sys.exit()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # 用户按下了结束键
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            t = ParseInstr()
            n = R_name
            b = R_bool
            Speaker(n[0], b[0], n[1], b[1], n[2], b[2], t)
    pygame.display.update()  # 显示图片
