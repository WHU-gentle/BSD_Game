#!/usr/bin/python
#--coding:utf-8--
'''
实现了文档中的人物x说话y时的控制效果
并在主函数部分进行了测试
测试复现方法：运行后，分别敲击键盘的a,s,d键
'''

import pygame,sys
import pygame.freetype  # 绘制文字的增强库
import io




def InitWindows(width, height, title):
    '''
    InitWindows函数
    function:构建一个宽度为width，高度为height、标题为title的窗口screen
    传入：窗口的宽度width,窗口的高度height
    传出：准备显示的屏幕screen
    '''
    # 初始化
    pygame.init()
    # 窗体设置
    size = width, height
    screen = pygame.display.set_mode(size)    # 创建窗口
    pygame.display.set_caption(title)  # 设置窗体名称
    return screen


def LoadBg(surface, bgPic):
    '''
    LoadBg函数
    function:在屏幕对象screen中显示背景图bgPic,
    传入：图片bgPic
    无传出
    '''
    background = pygame.image.load(bgPic)   # 载入图片
    surface.blit(background, (0, 0))   # 把图片background放到（0,0）的位置


def DisplayPlayer(i, pos):
    '''
    DisplayPlayer函数
    function:在位置pos显示人物照片pic
    传入：要显示的人物的照片pic，位置pos
    有效的pos值：left,mid,right
    无传出
    '''
    global screen
    # 规定人物显示的位置
    if pos == "left":
        role_position = 0
    elif pos == "mid":
        role_position = 400
    elif pos == "right":
        role_position = 700

    # 角色图片的相对路径
    pic_folder = './img/role/'
    role = pic_folder+str(i)+".png"
    # 显示角色图片
    role_pic = pygame.image.load(role)
    screen.blit(role_pic, (role_position, 158))


def DisplayDialog(text):
    '''
    DisplayDialog函数
    绘制文字、绘制对话框
    TODO:升级成响应式文字框：类似微信聊天中文字框随着文字多少而缩放的效果.第14周再做吧
    '''
    FONT = pygame.freetype.Font('font/simhei.ttf', 18)  # 字体路径，字体大小
    recSIZE = [10, 500]    # 对话框的大小
    recPOS = [980, 200]    # 对话框出现的位置
    wordPOS = [70, 531]  # 文字出现的位置
    recCOLOR = 223, 221, 132  # 对话框的颜色：黄色
    pygame.draw.rect(screen, recCOLOR, (recSIZE, recPOS))    # 绘制对话框
    wordRect1 = FONT.render_to(screen, wordPOS, text, size=30)  # 绘制文字


def ShowPic(text, figure1, figure2, figure3):
    '''
    ShowPic函数
    function:显示图片/文字在屏幕上
    传入：text是字符串，figure1是将会显示在左边的人物图片，figure2是中间、figure3是右边
    '''
    LoadBg(screen, "img/bg/bg1.png")
    if pic1:
        # 显示pic1
        DisplayPlayer(figure1, "left")
    if pic2:
        # 显示pic2
        DisplayPlayer(figure2, "mid")
    if pic3:
        DisplayPlayer(figure3, "right")
    DisplayDialog(text)
    pygame.display.update()
 

def DecidePic(LPic, AllowL, MPic, AllowM, RPic, AllowR, Dia):
    '''
    DecidePic函数
    function:通过指定show_pic_1,show_pic_2的布尔值，指定某一张/几张图片显示出来
    传入参数：LPic是显示在左边的图片文件名，AllowL是布尔值、表明左边的图片是否被允许显示；
             同理，M表示中间；R表示右边
             Dia是将要显示的文字
    '''
    pic1 = AllowL
    pic2 = AllowM
    pic3 = AllowR
    # 把布尔值传递给显示函数
    ShowPic(Dia, LPic, MPic, RPic)


def Speaker(figureL, allowL, figureM, allowM, figureR, allowR, text):
    '''
    Speaker函数
    function:指定人物及其位置，指定对话内容
    传入参数：
            figureL是显示在左边的人物文件名
            allowL=True时，figureL可以被显示；为False时，不显示
            M,R同理
            text是要显示的文字
    '''
    global pic1
    global pic2
    global pic3
    pic1 = allowL
    pic2 = allowM
    pic3 = allowR
    DecidePic(figureL, pic1, figureM, pic2, figureR, pic3, text)


# 初始化窗口
screen = InitWindows(1000, 700, "BSDGame")


'''
while True:  # 无限循环直至用户点击×
    for event in pygame.event.get():
        if event.type == pygame.QUIT:  # 用户按下了结束键
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_a:
                Speaker("1", True, "2", False, "3", False, "hello,world")
            elif event.key == pygame.K_s:
                Speaker("1", True, "2", True, "3", False, "Nice to meet you")
            elif event.key == pygame.K_d:
                Speaker("3", True, "2", True, "3", False, "Remember me?")
    pygame.display.update()  # 显示图片
'''

