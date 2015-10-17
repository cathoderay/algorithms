""" Run it like:
    $ python benchmark.py < inputs/BR.txt
"""

from timeit import timeit

from graph import Graph
from dijkstra import dijkstra
from dijkstra_h import dijkstra_h


G = Graph()
G.build_graph()

s = 2646
print timeit(lambda : dijkstra(G, s), number=1)
print timeit(lambda : dijkstra_h(G, s), number=1)


# output for BR.txt
#2.55977678299
#0.0487070083618

# output for map.txt
#0.00156283378601
#0.000765800476074

