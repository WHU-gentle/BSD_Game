import os
import sys
import pygame
import pygame.freetype  # 绘制文字的增强库
import io
import time
#from CtlClass import *

# 游戏资源存储
pic_bg = []
pic_art = {}
article = []
event = {}
sentence = {}

# 读取结构化剧本文件
with open(u"./text/Chapter1.txt", encoding='UTF-8') as data:
    for line in data.readlines():
        if line == '\n':
            continue
        article.append(str(line).lstrip())
num = -1  # 记录行数
for col in article:
    num = num + 1
    col = col.split(' ')
    if col[0] == 'background':
        pic_bg.append(col[2][1:-3])
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

# 初始化
pygame.init()
# 1.窗体设置
size = width, height = 1000, 700  # 通过函数传递参数 设置固定的窗口大小
screen = pygame.display.set_mode(size)    # 创建窗口
# 2.背景图片的设置
BLACK = 0, 0, 0  # 通过函数传递参数 设置窗口背景颜色
screen.fill(BLACK)  # 设置窗口背景颜色
background = pygame.image.load("./img/bg/bg1.jpg")  # 载入背景图片
screen.blit(background, (0, 0))  # 把图片background放到（0,0）的位置
# 3.窗体标题栏的设置
# 4.矩形框的设置
#r1POS=0,50,500,100  # r1rect矩形框的左上角坐标x,y,矩形框的宽度，高度
#r1WIDTH=0   # 矩形的边框宽度。0表示填充矩形
#r1rect=pygame.draw.rect(screen,GREEN,r1POS,r1WIDTH)

# 5.文字的设置
BLACK = 0, 0, 0
WHITE = 255, 255, 255
GREEN = 95, 171, 84
micFONT = pygame.freetype.Font('C://Windows//Fonts//simhei.ttf', 18)  # 字体路径，字体大小


class Text():
    """
    role: 字符串代表角色名字
    position: 角色位置
    talk: 角色所说的话
    """
    def __init__(self, role, position, talk):
        self.role = role
        self.position = position
        self.talk = talk
        self.diag = pygame.image.load("./img/diag_board.jpg")
        self.role_pic = pygame.image.load(pic_art[self.role])  # 加载图片

    def display(self):
        choicePOS = [70, 531]  # 对话出现的位置
        if self.position == '左':
            role_position = 0
        elif self.position == '中':
            role_position = 400
        elif self.position == '右':
            role_position = 700
        screen.blit(self.role_pic, (role_position, 0))  # 显示角色图片
        screen.blit(self.diag, (40, 500))  # 显示对话背景
        wordRect1 = micFONT.render_to(screen, choicePOS, self.talk, fgcolor=BLACK, size=30)  # 输出对话内容
        choicePOS[1] = choicePOS[1] + 30


# 剧情发展

for col in article:
    '''for event in pygame.event.get():
        if event.type == pygame.QUIT:  # 用户按下了结束键
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            break'''
    t = 0
    if '9' >= col[0][0] >= '1':
        index = sentence[col[0]]
        sen = article[index]
        sen = sen.split(' ')
        TEXT = Text(sen[1], sen[2], sen[3][1: -3])
        TEXT.display()
        t = int(len(sen[3])/8)
    pygame.display.update()  # 显示图片
    time.sleep(t)

'''
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # 用户按下了结束键
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            text = Text(1, 0,file_dialog)
        # 说明：用户输入A/B/C选择选项
        elif event.type==pygame.KEYDOWN:
            if event.key==pygame.K_a :
                print("A choice")
                text = Text(2, 1,option1)
            elif event.key==pygame.K_b:
                print("B choice")
                text = Text(3, 2,option2)
            elif event.key==pygame.K_c:
                print("C choise")
                text = Text(4, 2,option3)
        elif event.type==pygame.MOUSEMOTION:    # 设计时用鼠标获得当前位置，定位用
            print("[MOUSEMOTION]:",event.pos,event.rel,event.buttons)
        elif event.type==pygame.MOUSEBUTTONUP:  # 设计时用鼠标获得当前位置，定位用
            print("[MOUSEBUTTONUP]:",event.pos,event.button)
        elif event.type==pygame.MOUSEBUTTONDOWN:    # 设计时用鼠标获得当前位置，定位用
            print("[MOUSEBUTTONDOWN]:",event.pos,event.button)
    pygame.display.update() # 显示图片
'''

