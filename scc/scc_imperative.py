#!/usr/bin/python3

import numpy as np
import random
import time


def graph_dict(edges, reverse=False):
    
    # get the set of nodes:
    nodes = np.unique(edges.flatten())
    
    # initialize output:
    out = {node: {"seen": False, "adjacent": []} for node in nodes}
    
    # each edge consists of a node and its adjecent node:
    for node, adjacent_node in edges:
        
        # swap nodes if reverse=True:
        if reverse:
            node, adjacent_node = adjacent_node, node
        
        # add to dictionary:
        out[node]["adjacent"].append(adjacent_node)
        
    return out







def dfs_loop(edges, reverse=False):
    
    # conveniently redefine graph as a dictionary:
    graph = graph_dict(edges, reverse=reverse)
    
    
    # all unseen nodes:
    unseen_nodes = [n for n in graph if not graph[n]["seen"]]
    print("number of unseen nodes: {}".format(len(unseen_nodes)))

    # initialize 'finishing time':
    finishing_time = {}
    ft = 1
    
    # initialize connected components:
    ccs = {}


    while unseen_nodes:
    
        # set the base node:
        node = max(unseen_nodes)
        
        # and mark it down as 'seen':
        graph[node]["seen"] = True

        # we leave breadcrums along our path to find our way back:
        breadcrums = [node]

        # initialize list of unseen ajacent nodes
        unseen_adj_nodes = [a for a in graph[node]["adjacent"] if not graph[a]["seen"]]

        # initialize failsafe for the main while-loop:
        failsafe_max = len(graph)**3
        failsafe = 0

        # iterate until there is no path left to traverse (no more breadcrums):
        while breadcrums and failsafe < failsafe_max:
            
            if unseen_adj_nodes:    # traverse forward if there are unseen nodes:

                # take the next node from the unseen ones at random:
                node = random.choice(unseen_adj_nodes)

                # drop a breadcrum on the path traversed:
                breadcrums.append(node)

                # and mark it down as 'seen':
                graph[node]["seen"] = True


            else:    # back-track if there are no more unseen adjecent nodes:

                # pick up the last breadcrum and remember its corresponding node:
                node = breadcrums.pop()

                # and assign a finishing time to this node: 
                finishing_time[node], ft = ft, ft+1
                
                # set the current node to be the last of the remaining breadcrums:
                if breadcrums: node = breadcrums[-1]


            # prepare for next iteration:
            unseen_adj_nodes = [a for a in graph[node]["adjacent"] if not graph[a]["seen"]]
            
            # increment the failsafe iterator
            failsafe +=1
            
            #print(finishing_time)
        
        
        
        ccs[node] = len(finishing_time) - sum(ccs.values())
            
                
            
        # end of the inner while loop
        unseen_nodes = [n for n in graph if not graph[n]["seen"]]
        print("number of unseen nodes: {}".format(len(unseen_nodes)))


    # end of the outer while loop
    return finishing_time, ccs



################################################################################



with open("simple.txt", "r") as f:
        edges = []
        for line in f:
            edge = list(map(int, line.split()))
            edges.append(edge)

edges = np.array(edges)






# first run dfs-loop on the reverse graph:
relabel, _ = dfs_loop(edges, reverse=True)

print([relabel[i+1] for i in range(9)])

# then relabel the nodes according to their finishing times:
edges = np.array([(relabel[e[0]], relabel[e[1]]) for e in edges])

# run dfs-loop on the relabeled graph:
_, sccs = dfs_loop(edges)

# dictionary for undoing relabeling:
undo_relabel = {v: k for k,v in relabel.items()}

# undo relabeling:
sccs = {undo_relabel[k]: v for k,v in sccs.items()}

print(sorted(sccs.values(), reverse=True)[:5])



# [434821, 968, 459, 313, 211]






