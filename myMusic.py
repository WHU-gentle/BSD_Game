import pygame

'''
同时只能有一个音乐播放，下一个音乐的启动会让上一个自动终止，并且在后继播放结束后不会再接着播放前一音乐
所以一般情况下，不需要调用stop()函数，除非特殊情况
'''
class Music():
    #music_id ：音乐文件名去后缀部分，可以在剧本的台词后加整型标号，进而传入
    #music_pattern :默认为‘MP3’,如果为其他格式，可以显式传入或修改类中参数
    #path : 默认为空字符串，即为当前文件夹，如果不在当前文件夹，则可以显式传入前缀或者修改类中参数
    def __init__(self, music_id,music_pattern = 'mp3',path = './sound/text'):
        self.music_id = music_id
        self.music_path = path+str(music_id)+'_bgm.'+music_pattern
        self.m = pygame.mixer_music
        pygame.init()

    def play(self):
        try:
            self.m.load(self.music_path)
            self.m.play(-1)
        except:
            #用于测试过程中发现音乐文件的缺失，项目完成后将控制台窗口默认不显示时，不会影响游戏界面，所以不需修改
            print("未找到文件:"+self.music_path)
    def stop(self):
        try:
            self.m.stop()
        except:
            #防止报错
            pass




