

def merge(l, r):
    s = []
    while l and r:
        if l[0] <= r[0]:
            s.append(l.pop(0))
        else:
            s.append(r.pop(0))
    return s + r if not l else s + l


def merge_sort(l):
    if len(l) == 1: return l
    mid = int(len(l)/2)
    le = merge_sort(l[:mid])
    ri = merge_sort(l[mid:])

    return merge(le, ri)


if __name__ == '__main__':
    l = [5, 1, 3, 4, 1]
    print(merge_sort(l))
