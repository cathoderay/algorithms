def ccw(A, B, C):
    return (B[0] - A[0])*(C[1] - A[1]) - \
           (B[1] - A[1])*(C[0] - A[0])


def distance(A, B):
   return (A[0] - B[0])**2 + (A[1] - B[1])**2


def is_convex(pts):
    n = len(pts)
    for i in range(n):
        if ccw(pts[i], pts[(i+1)%n], pts[(i+2)%n]) < 0:
            return False
    return True


def interior_elimination(pts):
    A = max(pts, key=lambda p: p[0] + p[1])
    B = max(pts, key=lambda p: p[0] - p[1])
    C = max(pts, key=lambda p: p[1] - p[0])
    D = max(pts, key=lambda p: -p[0] - p[1])

    # only 3 points? eliminate everything!
    if len(set([A, B, C, D])) == 3:
        return list(set([A, B, C, D]))

    new_pts = []
    for p in pts:
        if not (ccw(B, A, p) > 0 and
            ccw(A, C, p) > 0 and
            ccw(C, D, p) > 0 and 
            ccw(D, B, p) > 0):
            new_pts.append(p)
    return new_pts


def read_input():
    import sys
    points = []
    for line in sys.stdin:
        points.append(tuple(map(float, line.split())))
    return points
