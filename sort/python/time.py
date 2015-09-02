import time
import timeit
import random

from selection import selection_sort
from insertion import insertion_sort
from merge import merge_sort 


strategies = [selection_sort, 
              insertion_sort, 
              merge_sort]


ns = [10**i for i in range(1, 6)]

for n in ns:
    l = range(n)
    random.shuffle(l)
    
    for s in strategies:
        print s.__name__, 
        print n, 
        x = l[:]
        print timeit.timeit((lambda: s(x)), number=3)
    print "-"*50

