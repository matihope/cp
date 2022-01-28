import pygame
import math

pygame.init()

SIZE = 800
win = pygame.display.set_mode((SIZE, SIZE))


def draw_circles():
    r = 25
    color1 = (200, 50, 50)
    color2 = (50, 200, 50)
    pygame.draw.circle(win, color2, (0, 0), r)
    pygame.draw.circle(win, color2, (SIZE, 0), r)
    pygame.draw.circle(win, color2, (SIZE, SIZE), r)
    pygame.draw.circle(win, color1, (0, SIZE), r)


def draw_lines(angle):
    start_pos = (0, 800)
    step = 0.1
    for i in range(1):
        
        
        pygame.draw.line(win, (200, 200, 200), start_pos, (end_x, end_y), 3)
        start_pos = (end_x, end_y)


def main():
    run = True
    clock = pygame.time.Clock()
    while run:
        clock.tick(60)
        for e in pygame.event.get():
            if e.type == pygame.QUIT:
                run = False

        win.fill((21, 21, 21))
        # draw
        draw_circles()
        draw_lines(-30)

        pygame.display.update()


if __name__ == '__main__':
    main()
