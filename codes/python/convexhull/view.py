""" This is a work in progress. 
    It's not a clean code, but it works and it was useful.
    This code helped me visualize what was happening when
    testing convex hull algorithms.

    Use it like: 
    python view.py < inputs/brazil.in
"""

import random
import sys, pygame
from graham import graham, read_input
from jarvis import jarvis
from andrew import andrew 
from helper import interior_elimination

from times import inside_rectangle, inside_circle, on_circle, inside_triangle


def plot(points):
    SIZE = (1024, 768)
    BLACK = (0, 0, 0)
    WHITE = (255, 255, 255)
    GREEN = (0, 255, 0)
    RED = (255, 0, 0)
    BLUE = (0, 0, 255)
    GRAY = (100, 100, 100)
    MARGIN = 50
    PANELW = 200
    SAMPLE = 100 
    LIMIT = 1000
    ZOOM = 10
    CIRCLE = 2

    up_sample = False
    down_sample = False
    x, y = 0, 0
    pygame.init()
    #ch = graham(points[:])
    #ch = jarvis(points[:])
    #ch = andrew(points[:])
    ch = graham(points[:])

    screen = pygame.display.set_mode(SIZE)


    def scale(points):
        xmax = max(points, key=lambda p: p[0])[0]
        xmin = min(points, key=lambda p: p[0])[0]
        ymin = min(points, key=lambda p: p[1])[1]
        ymax = max(points, key=lambda p: p[1])[1]
        dx = float(xmax - xmin)
        dy = float(ymax - ymin)

        # preventing division per zero
        if dy == 0: dy = 0.0001
        if dx == 0: dx = 0.0001

        wx = float(1024 - 2*MARGIN - PANELW)
        hy = float(768 - 2*MARGIN)
        
        pts = map(lambda p: (p[0] + -xmin, ymax - p[1]), points)

        pts = map(lambda p: (p[0]*724./dx, p[1]*668./dy), pts)

        xmaxk = max(pts, key=lambda p: p[0])[0]
        xmink = min(pts, key=lambda p: p[0])[0]
        ymaxk = max(pts, key=lambda p: p[1])[1]
        ymink = min(pts, key=lambda p: p[1])[1]
        dxk = (MARGIN + wx/2.) - (xmaxk - xmink)/2. 
        dyk = (MARGIN + hy/2.) - (ymaxk - ymink)/2. 

        pts = map(lambda p: (p[0] + dxk, p[1] + dyk), pts)

        pts =  map(lambda p: (int(p[0]), int(p[1])), pts) 
        #pygame.draw.circle(screen, (0, 255, 0), (MARGIN + int(wx/2.), MARGIN + int(hy/2.)), 2)
        return pts


    def random_points():
        wx = float(1024 - 2*MARGIN - PANELW)
        hy = float(768 - 2*MARGIN)
        #return [(random.randrange(-wx, wx), random.randrange(-hy, hy)) for i in range(SAMPLE)]
        #return inside_rectangle(SAMPLE)
        #return inside_circle(SAMPLE)
        #return on_circle(SAMPLE)
        return inside_triangle(SAMPLE)

    while 1:
        for event in pygame.event.get():
            if event.type == pygame.MOUSEMOTION:
                x, y = event.pos
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    sys.exit()
                elif event.key == pygame.K_UP:
                    up_sample = True
                elif event.key == pygame.K_DOWN and SAMPLE > 3:
                    down_sample = True
                elif event.key == pygame.K_r:
                    restart = True
                    points = random_points()
                    #ch = graham(points[:])
                    #ch = jarvis(points[:])
                    #ch = andrew(points[:])
                    ch = graham(points[:])
                    print len(ch)
                    #print ch
                elif event.key == pygame.K_e:
                   pts = interior_elimination(points) 
                   print len(points), len(pts)
                   points = pts

            elif event.type == pygame.KEYUP:
                if event.key == pygame.K_UP:
                    up_sample = False
                elif event.key == pygame.K_DOWN:
                    down_sample = False

        if up_sample: SAMPLE += 1
        if down_sample and SAMPLE > 3: SAMPLE -= 1

        screen.fill(WHITE)

        
        def draw_ch():
            #plot axis lines
            pygame.draw.aaline(screen, GRAY, (0, SIZE[1]/2), (SIZE[0] - PANELW, SIZE[1]/2), 2)
            pygame.draw.aaline(screen, GRAY, ((SIZE[0] - PANELW)/2, 0), ((SIZE[0] - PANELW)/2, SIZE[1]), 2)

            #plot convex hull edges
            pts = scale(ch)
            for p in range(1, len(pts)):
                pygame.draw.aaline(screen, BLUE, pts[p-1], pts[p], 2)
            pygame.draw.aaline(screen, BLUE, pts[-1], pts[0], 2)

            #plot points
            pts = scale(points)
            for point in pts:
                pygame.draw.circle(screen, RED, point, CIRCLE)
            pygame.draw.rect(screen, GRAY, (SIZE[0] - PANELW, 0, PANELW, SIZE[1]))

            #plot convex hull vertices
            pts = scale(ch)
            for p in pts:
                pygame.draw.circle(screen, BLACK, p, CIRCLE + 1)
    
        draw_ch()
    
        #plot text
        text = pygame.font.SysFont("", 20)
        label = text.render("Commands", 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, 0.5*MARGIN))


        text = pygame.font.SysFont("", 15)
        label = text.render("r: randomize points", 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, MARGIN))

        text = pygame.font.SysFont("", 15)
        label = text.render("e: eliminate points", 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, 1.5*MARGIN))

        label = text.render("up arrow: increase sample size", 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, 2*MARGIN))

        label = text.render("down arrow: decrease sample size", 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, 2.5*MARGIN))

        label = text.render("Sample size: %d" % SAMPLE, 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, 3*MARGIN))
        
        label = text.render("Mouse position: %d, %d" % (x, y), 1, WHITE)
        screen.blit(label, (SIZE[0] - PANELW + 20, 15*MARGIN))

        pygame.display.flip()


if __name__ == '__main__':
    plot(read_input())
