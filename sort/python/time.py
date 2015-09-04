import time
import timeit
import random

from selection import *
from insertion import *
from merge import *


strategies = [selection_sort, 
              insertion_sort, 
              merge_sort]


ns = [10**i for i in range(1, 6)]

for n in ns:
    l = list(range(n))
    random.shuffle(l)
    
    for s in strategies:
        print(s.__name__, 
              n, 
              timeit.timeit((lambda: s(l[:])), number=1))


    print("-"*50)

