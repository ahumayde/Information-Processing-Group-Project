import pygame
import keyboard
from sys import exit

def game_loop():
    pygame.init()
    pygame.mixer.init()
    pygame.mixer.Sound('X__X.wav').play()
    screen = pygame.display.set_mode((400, 640))
    lineY = pygame.Surface((2, 640))
    lineX = pygame.Surface((400, 2))
    wickerson = pygame.image.load("makeiscrap.png").convert()
    Square = pygame.transform.scale(wickerson, (80, 80))
    #Square = pygame.Surface((80, 80))
    #Square.fill('red')
    lineY.fill('white')
    lineX.fill('white')
    pygame.display.set_caption("Johnny")
    clock = pygame.time.Clock()
    x, y = 0, 0
    changes = {
        'up': (0, -80),
        'down': (0, 80),
        'left': (-80, 0),
        'right': (80, 0),
    }
    # font=pygame.font.Font('font/Pixeltype.ttf', 50)
    # sky_surface = pygame.image.load('graphics/Sky.png')
    # ground_surface = pygame.image.load('graphics/ground.png')
    # text_surface = font.render('Press any key to start', False, 'green')
    while True:
        screen.fill((0, 0, 0))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                print("Closing window...")
                pygame.quit()
                exit()
        # screen.blit(sky_surface, (0, 0))
        # screen.blit(ground_surface, (0, 300))
        # screen.blit(text_surface,(200,200))
        for key, (changex, changey) in changes.items():
            if keyboard.is_pressed(key) and not any(keyboard.is_pressed(k) for k in changes if k != key) and 0 <= x + changex <=320 and 0 <= y + changey <= 560:
                x += changex
                y += changey
        if keyboard.is_pressed("l"):
            wickerson = pygame.transform.rotate(wickerson, -90)
            Square = pygame.transform.scale(wickerson, (80, 80))
        if keyboard.is_pressed("r"):
            wickerson = pygame.transform.rotate(wickerson, 90)
            Square = pygame.transform.scale(wickerson, (80, 80))

        screen.blit(Square, (x, y))
        for i in range(80, 400, 80):
            screen.blit(lineY, (i, 0))
        for i in range(80, 640, 80):
            screen.blit(lineX, (0, i))
        pygame.display.update()

        clock.tick(80)
                   
game_loop()