#!/usr/bin/python3

################################################################################

import numpy as np
from random import shuffle

################################################################################

def graph_dict(edges, reverse=False):
    
    # get the set of nodes:
    nodes = np.unique(np.array(edges))
    
    # initialize output:
    out = {node: [] for node in nodes}
    
    # each edge consists of a node and its adjecent node:
    for node, adjacent_node in edges:
        
        # swap nodes if reverse=True:
        if reverse:
            node, adjacent_node = adjacent_node, node
        
        # add to dictionary:
        out[node].append(adjacent_node)
        
    return out

################################################################################

with open("SCC.txt", "r") as f:
        edges = []
        for line in f:
            edge = tuple(map(int, line.split()))
            edges.append(edge)
            

################################################################################





################################
#
#       LEGEND:
#
#  dfs  = depth-first search
#   g   = graph dictionary
#   n   = starting node
#   p   = path traversed
#   a   = adjacent node
#   u   = list of unseen nodes
#   s   = strongly connected component (base node and size)
#   t   = finishing time for each node after dfs (used for relabeling graph)
# t_inv = inverse of t (undo relabeling done by t)
#
################################


# recusive definition of dfs:
def dfs(g, n, p, u):
    #shuffle(g[n])
    for a in g[n]:
        if a in u:
            u.remove(a)
            p.append(a)
            dfs(g, a, p, u)
            

# the dfs loop:
def dfs_loop(edges, reverse=False):

    g = graph_dict(edges, reverse=reverse)
    u = list(np.unique(np.array(edges).flatten()))
    t, s, i = {}, {}, 0
    
    while u:
        n = u.pop()
        p = [n]
        dfs(g, n, p, u)
        
        while p:
            if [e for e in g[n] if e in u]:
                n = p[-1]
            else:
                n = p.pop()
                t[n] = i = i+1
            dfs(g, n, p, u)
            
        if not reverse: s[n] = len(t) - sum(s.values())

    if reverse:
        return t
    else:
        return s




def scc(edges):

    t = dfs_loop(edges, reverse=True)

    t_inv = {v:k for k,v in t.items()}

    edges = [[t[e[0]], t[e[1]]] for e in edges]

    s = dfs_loop(edges)

    s = {t_inv[k]: v for k,v in s.items()}
    
    return sorted(s.values(), reverse=True)[:10]



print(scc(edges))










