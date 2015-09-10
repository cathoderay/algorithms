

def merge(a, l, r):
    i = lp = rp = 0
    while lp < len(l) and rp < len(r):
        if l[lp] <= r[rp]:
            a[i] = l[lp]
            lp += 1
        else:
            a[i] = r[rp]
            rp += 1
        i += 1
    a[i:] = l[lp:] if lp < len(l) else r[rp:]
    return a


def merge_sort(a):
    if len(a) == 1: return a

    mid = len(a)//2
    l = merge_sort(a[:mid])
    r = merge_sort(a[mid:])

    return merge(a, l, r)


if __name__ == '__main__':
    l = [5, 1, 3, 4, 1]
    merge_sort(l)
    print(l)
