'''
案发现场场景：鼠标点击寻找线索
'''

import pygame
from ctlClass import InitWindows, DisplayWords, DisplayDialog, LoadBg, DisplayDialog

area = []           #线索对应区域
cluePic = []        #线索图片路径
clueText = []       #线索文字描述

dialogPos = [0, 550]            #对话框显示位置
cluePos = [125, 580]            #线索图片显示位置
arrowPos = [[8, 46], [11, 46]]  #箭头显示区域(左上和右下两点坐标)

def readTxt(fileName):
    '''
    readText函数：从txt文件中读取信息并存到数组中
    :param 文件名fileName
    :return: null
    '''
    with open(u"./text/" + fileName) as input_file:
        for line in input_file.readlines():
            curLine = line.strip().split(" ")
            clueText.append(curLine[-1])
            cluePic.append(curLine[4])
            area.append(list(map(int, curLine[0:4])))
    #print('area:', area)
    #print('clues:', clues)

def dispClue(point, posOfClue, text, pic):
    '''
    dispClue函数：如果鼠标点击的坐标在指定范围，则输出对应文字线索
    :param  point为鼠标点击时坐标，
            posOfClue为线索位置(cx,cy,cw,ch)，
            text为线索提示
    :return: null
    '''
    global screen
    px, py = point              #鼠标点击位置
    cx, cy, cw, ch = posOfClue  #线索区域
    if (cx <= px <= cx+cw) and (cy <= py <= cy+ch):
        DisplayDialog("img/dialog/dialogClue.png", dialogPos[0], dialogPos[1], 300, 600, text)     #显示提示框
        clue_pic = pygame.image.load('./img/clue/' + pic)               #显示线索图
        screen.blit(clue_pic, (cluePos[0], cluePos[1]))


#初始化场景
screen = InitWindows(1000, 700, "BSDGame")

def LoadScene():
    '''
    LoadScene函数：转换场景到案发现场，可在main中直接调用
    :return: 
    '''
    LoadBg(screen, "img/bg/crimeScene.png")
    tips = "这是案发现场，去搜寻一番吧，说不定会发现重要的线索..."
    DisplayDialog("img/dialog/dialog.png", dialogPos[0], dialogPos[1], 20, 600, tips)
    readTxt("clue.txt")
    while True:  # 无限循环直至用户点击×
        for event in pygame.event.get():
            if event.type == pygame.QUIT:  # 用户按下了结束键
              sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                px, py = event.pos
                if (arrowPos[0][0] <= px <= arrowPos[0][1]) and (arrowPos[1][0] <= py <= arrowPos[1][1]):        #返回对话场景
                    return
                print(event.pos)
                for i in range(len(area)):                      #循环判断是否点击线索区域
                    dispClue(event.pos, area[i], clueText[i], cluePic[i])
        pygame.display.update()  # 显示图片





