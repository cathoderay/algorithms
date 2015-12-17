""" Use it like:
    python andrew.py < inputs/brazil.in
"""
from helper import ccw, read_input, is_convex, interior_elimination


def half_hull(pts):
    h = []
    for p in pts:
        while len(h) >= 2 and ccw(h[-2], h[-1], p) <= 0:
            h.pop()
        h.append(p)
    return h


def andrew(points, cutoff=False):
    if cutoff: points = interior_elimination(points)
    pts = sorted(set(points))
    H = half_hull(pts)[:-1] + \
        half_hull(reversed(pts))[:-1]

    assert is_convex(H)
    return H
          

if __name__ == '__main__':
    pts = read_input()
    import timeit
    print timeit.timeit(lambda : andrew(pts), number=1) 
    print andrew(pts)
