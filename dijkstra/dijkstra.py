#!/usr/bin/python3

# load the graph:
g = {}
with open('simple.txt', 'r') as f:
    for l in f:
        l = l.split()
        g[int(l[0])] = dict(list(map(lambda s: tuple(map(int, s.split(','))), l[1:])))


####  LEGEND:  #################################################################
## 
## n = current node
## 
## g = graph, adjacency dict
##       {node: {adjacent_node: length, ... }, ... }
##
## l = dict of lengths from starting node
##       {node: length, ... }
##
## e = edges connecting seen and unseen nodes (with their respective distances)
##       {(node_seen, node_unseen): length, ... }
##
################################################################################

# initialize starting node:
l, n, e = {1: 0}, 1, {}
for i in g[n]:
    e[(n,i)] = g[n][i] + l[n]

# the main loop
while e:
    emin = min(e, key=e.get)
    n = emin[1]
    l[n] = e.pop(emin)

    for i in g[n]:
        e[(n,i)] = g[n][i] + l[n]

    e = {k:v for k,v in e.items() if k[1] not in l}



print(l)
