# This is an example of 
# how the outputs in the report can be 
# reobtained.
# 
# America's Graph
# ---------------
# Run it like this:
# $ python work.py < inputs/map.txt
#
# Brazil's Graph
# --------------
# In order to obtain the results for
# Brazil's graph, just change the variables
# 's' and 'f' in this file and run it like:
# $ python work.py < inputs/BR.txt
#

from graph import Graph
from kruskal import kruskal
from dijkstra_h import path, dijkstra_h


G = Graph()
G.build_graph()


# minimmum spanning tree
mst = kruskal(G)
length = sum([edge.weight for edge in mst])
print length


# shortest path from city s to f
s = 93; f = 112
d, p = dijkstra_h(G, s) 
print d[f]


# shortest path tree from city s
s = 104
d, p = dijkstra_h(G, s)
edges = []
for v in G.vertices():
    edges += path(p, s, v)
edges = set(edges)
cost = 0
for a, b in edges:
    cost += G.weight(a, b)
print cost
