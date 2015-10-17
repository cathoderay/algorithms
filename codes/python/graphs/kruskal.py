""" Run it like:
    $ python kruskal.py < inputs/map.txt
"""

from timeit import timeit
from pprint import pprint
from heapq import heapify, heappop

from graph import Graph, Edge
from quick_find import QF
from quick_union import QU
from quick_unionw import QUW


def kruskal(G, UF=QUW):
    mst = []
    edges = map(lambda e: e.to_heapify(), G.edges())
    heapify(edges)

    uf = UF(G.nv) 

    while len(mst) < (G.nv - 1):
        w, a, b = heappop(edges) 
        if not uf.connected(a, b):
            uf.add(a, b)
            mst.append(Edge(a, b, w))
    return mst
 

if __name__ == '__main__':
    G = Graph()
    G.build_graph()

    for uf in [QF, QU, QUW]:
        print uf.__name__, timeit(lambda : kruskal(G, uf), number=1)
        print "MST length: ", sum([edge.weight for edge in kruskal(G, uf)]) 

