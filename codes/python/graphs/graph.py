
import sys
from pprint import pprint

import bfs


class Edge:
    def __init__(self, a, b, w):
        self.a = a
        self.b = b
        self.weight = w

    def to_heapify(self):
        return (self.weight, self.a, self.b)

    def __repr__(self):
        return "%s-%s (%s)" % (self.a, self.b, self.weight)


class Graph:
    def __init__(self):
        self.adj = {}
        self.nv = self.ne = 0
    
    def __add_edge(self, a, b, w=1):
        if a in self.adj:
            self.adj[a].append(Edge(a, b, w))
        else:
            self.adj[a] = [Edge(a, b, w)]
            self.nv += 1

    def add_edge(self, a, b, w=1):
        self.__add_edge(a, b, w)
        self.__add_edge(b, a, w)
        self.ne += 1

    def add_vertice(self, a):
        if not a in self.adj:
            self.adj[a] = []
            self.nv += 1

    def vertices(self):
        return self.adj.keys()

    def edges(self):
        return filter(lambda e: e.a <= e.b, 
                      [e for k, v in self.adj.iteritems()
                      for e in v])

    def edges(self):
        return [e for k, v in self.adj.iteritems() for e in v]

    def build_graph(self):
        for line in sys.stdin:
            a, b, w = line.split()
            self.add_edge(int(a), int(b), float(w))

    def loops(self):
        return filter(lambda x: x.a == x.b, self.edges())

    def is_connected(self):
        m, d, p = bfs.bfs(self, 1) 
        for a in self.adj:
            if not m[a]:
                return False
        return True



if __name__ == '__main__':
    """ Run it like:
     $ python graph.py < inputs/graph.in """

    G = Graph()
    G.build_graph()

    pprint(G.adj)
    print " |V| = %s" % G.nv
    print " |E| = %s" % G.ne
    print G.is_connected()

