

def insertion_sort(l):
    for i in xrange(1, len(l)):
        p = i
        while p > 0 and l[p] < l[p - 1]:
            l[p], l[p - 1] = l[p - 1], l[p]
            p -= 1
    return l

