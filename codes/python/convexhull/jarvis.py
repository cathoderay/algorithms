""" Use it like:
    python jarvis.py < inputs/brazil.in
"""
import random
from helper import ccw, read_input, distance, is_convex, interior_elimination


def jarvis(points, cutoff=False):
    if cutoff: points = interior_elimination(points)

    #removing duplicate points
    pts = list(set(points))
   
    P0 = min(pts, key=lambda p: (p[1], p[0]))
    H = [P0]
    
    # Since 'for loops' works as generators, 'H' is gonna be 
    # populated within the loop and 'h' will always be
    # the most recent added. In the last iteration, 'H' won't
    # be updated (case when P0 is reached again) 
    # and the 'for loop' ends.
    for h in H:
        a = h 
        for b in pts:
            if ccw(h, a, b) < 0 or (ccw(h, a, b) == 0 and \
                distance(h, b) > distance(h, a)):
                a = b
        if a is not P0:
            H.append(a)

    assert is_convex(H)
    return H
 

if __name__ == '__main__':
    pts = read_input()
    import timeit
    print timeit.timeit(lambda : jarvis(pts), number=1) 
    print jarvis(pts)
