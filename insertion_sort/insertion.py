

def insertion_sort(l):
    c = 0
    t = 0
    for i in xrange(1, len(l)):
        p = i
        while p > 0 and l[p] < l[p - 1]:
            c += 1
            l[p], l[p - 1] = l[p - 1], l[p]
            t += 1
            p -= 1
    print c, t, 
    return l

