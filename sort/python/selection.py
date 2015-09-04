

def selection_sort(l): 
    for i in range(len(l) - 1):
        m = i
        for k in range(i + 1, len(l)):
            if l[k] < l[m]: 
                m = k
        l[i], l[m] = l[m], l[i]
    return l


if __name__ == '__main__':
    l = [5, 1, 3, 4, 1]
    print(selection_sort(l))
