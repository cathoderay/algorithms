import random
import math

from helper import ccw
from graham import graham
from jarvis import jarvis
from andrew import andrew
from timeit import timeit 


def inside_rectangle(n, w=1000, h=500):
    #pts = [(0, 0), (1000, 500), (0, 500), (1000, 0)]
    pts = []
    return pts + [(random.random()*w, 
                   random.random()*h) 
                  for i in range(n)]


def inside_circle(n, r=1000):
    pts = []
    for i in range(n):
        x = random.random()*r
        if random.random() > 0.5: x = -x
        y = random.random()*math.sqrt((r)**2 - x**2)
        if random.random() > 0.5: y = -y
        pts.append((x, y))
    return pts


def inside_triangle(n, v1=(500, 500), v2=(1000, 0)):
    "http://mathworld.wolfram.com/TrianglePointPicking.html"
    #pts = [(0, 0), (500, 500), (1000, 0)] 
    pts = []
    for i in range(n):
        while True:
            a1 = random.random() 
            a2 = random.random()
            pt = (a1*v1[0]+ a2*v2[0], a1*v1[1] + a2*v2[1])
            if ccw(v2, v1, pt) > 0:
                break #skipping when it's in the other side of paralelogram
        pts.append(pt)
    return pts
            

def on_circle(n, r=100):
    pts = []
    for i in range(n):
        x = random.random()*r
        if random.random() > 0.5: x = -x
        y = math.sqrt(r**2 - x**2)
        if random.random() > 0.5: y = -y
        pts.append((x, y))
    return pts


if __name__ == '__main__':
    ns = [10000*i for i in range(1, 12)]
    algorithms = [jarvis, graham, andrew]
    input_type = [inside_rectangle, inside_circle, inside_triangle, on_circle]
    for elimination in [False, True]:
        for type in input_type:
            print type.__name__, elimination
            print "n", 
            for algorithm in algorithms: print algorithm.__name__,
            print
            for n in ns:
                print n,
                for algorithm in algorithms:
                    print timeit(lambda: algorithm(type(n), elimination), number=1),
                print
