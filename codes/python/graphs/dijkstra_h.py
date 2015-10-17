""" Run it like:
    $ python dijkstra_h.py < inputs/map.txt
"""

import sys
from graph import Graph
from heapq import heappop, heappush


def dijkstra_h(G, s):
    d = [sys.maxint]*(G.nv + 1)
    p = [-1]*(G.nv + 1)

    d[s] = 0 
    S = set()
    Q = [(d[s], p[s], s)] 

    while Q:
        bd, pa, a = heappop(Q)
        if a in S: continue
        S.add(a)
        d[a] = bd
        p[a] = pa
        for edge in G.adj[a]:
            b = edge.b
            w = edge.weight
            heappush(Q, (d[a] + w, a, b))
    return d, p


def path(p, s, t):
    r = []
    while s != t:
        r.append((p[t], t))
        t = p[t]
    r.reverse()
    return r


if __name__ == '__main__':
    G = Graph()
    G.build_graph()

