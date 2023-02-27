import pygame
from sys import exit
import time



pygame.init()
screen = pygame.display.set_mode((400, 640))
lineY=pygame.Surface((2, 640))
lineX=pygame.Surface((400, 2))
Square=pygame.Surface((80, 80))
Square.fill('red')
lineY.fill('white')
lineX.fill('white')


pygame.display.set_caption("Pong")
clock = pygame.time.Clock()
# font=pygame.font.Font('font/Pixeltype.ttf', 50)

# sky_surface = pygame.image.load('graphics/Sky.png')
# ground_surface = pygame.image.load('graphics/ground.png')
# text_surface = font.render('Press any key to start', False, 'green')
x,y=0,0
up = False
down = False
left = False
right = False
while True:
    screen.fill((0, 0, 0))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()



    # screen.blit(sky_surface, (0, 0))
    # screen.blit(ground_surface, (0, 300))
    # screen.blit(text_surface,(200,200))
    if pygame.key.get_pressed()[pygame.K_UP] and not up and y > 0:
        y-=80
        up=True

        down = False
        left = False
        right = False
    elif not pygame.key.get_pressed()[pygame.K_UP]:
        up = False


    if pygame.key.get_pressed()[pygame.K_DOWN] and not down and y < 560:
        y += 80
        down=True
        up = False
        left = False
        right = False
    elif not pygame.key.get_pressed()[pygame.K_DOWN]:
        down = False

    if pygame.key.get_pressed()[pygame.K_LEFT] and not left and x>0:
        x-=80
        left=True
        up = False
        down = False
        right = False
    elif not pygame.key.get_pressed()[pygame.K_LEFT]:
        left = False

    if pygame.key.get_pressed()[pygame.K_RIGHT] and not right and x<320:
        x += 80
        right=True
        up = False
        down = False
        left = False
    elif not pygame.key.get_pressed()[pygame.K_RIGHT]:
        right = False




    screen.blit(Square,(x,y))
    for i in range(80,400,80):
        screen.blit(lineY, (i, 0))
    for i in range(80,640,80):
        screen.blit(lineX,(0,i))
    pygame.display.update()

    clock.tick(60)
