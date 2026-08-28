#输入文字
import pygame
import sys
#初始化，定义了屏幕大小 字体规范 初始化文本内容
pygame.init()
screen = pygame.display.set_mode((400, 600))

pygame.key.start_text_input()
font = pygame.font.SysFont("simhei", 20)
input_text=""
cursor_visible = True
last_blink = pygame.time.get_ticks()
#检测输入内容
while True:
    if pygame.time.get_ticks() - last_blink > 500:
        cursor_visible = not cursor_visible
        last_blink = pygame.time.get_ticks()

    for event in pygame.event.get():
        #退出键
        if event.type == pygame.QUIT:
            sys.exit()
        #输入信息
        if event.type == pygame.KEYDOWN:
            #回车打印
            if event.key == pygame.K_RETURN:
                print("你输入了：",input_text)
                input_text = ""
            #退格键
            elif event.key == pygame.K_BACKSPACE:
                input_text = input_text[:-1]
            else:
                input_text += event.unicode

    #画面打印
    #先覆盖
    screen.fill((30,30,30))

    display_text = f"> {input_text}"+("|"if cursor_visible else "")
    txt_surf=font.render(display_text, True, (255,255,255))
    screen.blit(txt_surf, (0,500))
    pygame.display.update()