

def insertion_sort(l):
    for j in range(1, len(l)):
        k = l[j]
        i = j - 1
        while i > -1 and l[i] > k:
            l[i + 1] = l[i] 
            i -= 1
        l[i + 1] = k
    return l


if __name__ == '__main__':
    l = [5, 1, 3, 4, 1]
    print(insertion_sort(l))
