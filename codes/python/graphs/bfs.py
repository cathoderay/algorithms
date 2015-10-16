
from Queue import Queue

import graph


def bfs(G, s):
    # initialization
    d = [-1]*(G.nv + 1)
    m = [False]*(G.nv + 1)
    p = [-1]*(G.nv + 1)

    # visit source
    m[s] = True
    d[s] = 0
    Q = Queue()
    Q.put(s)

    # let's visit the rest!
    while not Q.empty():
        a = Q.get()
        for edge in G.adj[a]:
            b = edge.b
            if not m[b]:
                d[b] = d[a] + 1
                p[b] = a
                m[b] = True
                Q.put(b)
    return (m, d, p)


if __name__ == '__main__':
    """ Run it like:
    $ python bfs.py < inputs/graph.in"""

    G = graph.Graph()
    G.build_graph()
    print bfs(G, 1)
