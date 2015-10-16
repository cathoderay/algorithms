import sys
from graph import Graph


def dijkstra(G, s):
    d = [sys.maxint]*(G.nv + 1)
    p = [-1]*(G.nv + 1)

    d[s] = 0 
    S = set()
    Q = G.vertices()

    while Q:
        a = min(Q, key=lambda v: d[v])
        Q.remove(a)
        S.add(a)
        for edge in G.adj[a]:
            b = edge.b
            w = edge.weight
            if d[b] > d[a] + w:
                d[b] = d[a] + w
                p[b] = a
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

    d, p = dijkstra(G, 2646)
    print path(p, 1, 2646)

    d, p = dijkstra(G, 1)
    print path(p, 1, 2646)

    #edges = []
    #for v in G.vertices():
    #    if v != 104:
    #        edges += path(p, 2646, v)
    #edges = set(edges)

    #for a, b in edges:
    #    print "P%s P%s edge" % (a, b)

    #for i in range(1, G.nv):
    #    print "P%s vertex" % (i)

    #cost = 0
    #for a, b in edges:
    #    for k in G.adj[a]:
    #        if k.b == b:
    #            cost += k.weight
    #            break
    #print cost

