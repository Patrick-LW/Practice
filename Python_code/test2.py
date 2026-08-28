#进行图片的加载播放
import pygame

pygame.init()

screen = pygame.display.set_mode((400,600))
pygame.display.set_caption("ai小猫")
#加载图片
cat_image = [
        pygame.transform.scale(pygame.image.load("sprites/idle_0.png").convert_alpha(),(400,390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_1.png").convert_alpha(),(400,390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_2.png").convert_alpha(),(400,390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_3.png").convert_alpha(),(400,390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_4.png").convert_alpha(),(400,390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_5.png").convert_alpha(),(400, 390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_4.png").convert_alpha(),(400, 390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_3.png").convert_alpha(),(400,390)),
        pygame.transform.scale(pygame.image.load("sprites/idle_2.png").convert_alpha(),(400,390)),
    ]
current_image = 0
counter = 0
delay = 8 #锁帧，调快慢
clock = pygame.time.Clock()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    counter += 1
    if counter >= delay:
        current_image = (current_image + 1) % len(cat_image)
        counter = 0
    current_img = cat_image[current_image]
    screen.fill((35,35,35))
    screen.blit(cat_image[current_image],(0,0))
    pygame.display.update()
    clock.tick(30)
pygame.quit()