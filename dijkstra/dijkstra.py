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
##		format: integer
## 
## g = graph, adjacency dict
##      format: {node: {adjacent_node: length, ... }, ... }
##
## l = dict of lengths from starting node
##      format: {node: length, ... }
##
## e = edges connecting seen and unseen nodes (with their respective distances)
##      format: {(node_seen, node_unseen): length, ... }
##
## emin = edge in e with minimal path length 
##		format: (node_seen, node_unseen)
##
################################################################################

# initialize starting node:
l, n, e = {1: 0}, 1, {}
for i in g[n]:
    e[(n,i)] = g[n][i] + l[n]

# the main loop
while e:
    emin = min(e, key=e.get)                        # get minimum edge
    n = emin[1]                                     # set current node accordingly
    l[n] = e.pop(emin)								# set corresponding path length (and remove edge from e)

    for i in g[n]:									# iterate over all nodes adjacent to new node n
        e[(n,i)] = g[n][i] + l[n]					# add new cross edges to e

    e = {k:v for k,v in e.items() if k[1] != n} 	# remove redundant edges connecting two seen nodes



print(l)
