""" Use it like:
    python graham.py < inputs/brazil.in
"""
from helper import ccw, is_convex, read_input, interior_elimination


def compare(P0, B, C, to_ignore):
    d = ccw(P0, C, B) 
    if d is not 0: return 1 if d > 0 else -1
    if distance(P0, B) > distance(P0, C):
        to_ignore[C] = True
        return -1 
    to_ignore[B] = True
    return 1 


def graham(points, cutoff=False):
    if cutoff: points = interior_elimination(points)

    #removing duplicate points
    pts = list(set(points)) 

    P0 = min(pts, key=lambda p: (p[1], p[0]))
    pts.remove(P0)

    # sorting by polar angles and ignoring collinear points 
    # (keeping the farthest one)
    to_ignore = {}
    pts.sort(lambda B, C: compare(P0, B, C, to_ignore))

    H = [P0] + pts[:2]

    for i in range(2, len(pts)):
        if pts[i] in to_ignore: continue
        while ccw(H[-2], H[-1], pts[i]) <= 0:
            H.pop()
        H.append(pts[i])

    assert is_convex(H)
    return H


if __name__ == '__main__':
    pts = read_input()
    import timeit
    print timeit.timeit(lambda : graham(pts, True), number=1)
    print graham(pts)


    """
    #generating eps output...
    p = {}
    for i, x in enumerate(points):
       p[x] = "P%d" % (i+1)
    ch = graham(points)
    print ch

    for x in ch:
        print p[x], "vertex"

    print "---"

    n = len(ch)
    n = len(ch)
    for i in range(n):
        print p[ch[i]], p[ch[(i+1)%n]], "edge"
    """
