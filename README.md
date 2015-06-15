# Basic Algorithms written in C++, Haskell, Julia, Python and Mathematica

This repo contains the codes of some basic algorithms written in C++, Haskell, Julia, Python and Mathematica. I wrote these codes as part of an online course about algorithms.

I learned these algorithms as part of my transition from theoretical physics (string theory) to data science. To make things interesting, I decided to simultaneously explore several different computer languages.

**Note:** I was completely new to many of these languages, so any pointers (pardon the pun) are very much appreciated! So please, feel free to contact me: **kristian.holsheimer@gmail.com**.


## Contents

* **merge-sort**: This algorithm takes an unsorted list of *n* integers and returns its sorted version in *O*(*n* log *n*) time. As a perk, my *C++* and *Julia* implementation of the algorithm also keeps track of the *number of inversions* required. Other languages I wrote this algorithm in are *Mathematica* and *Haskell*.

* **quick-sort**: Like merge-sort, quick-sort takes an unsorted list of *n* integers and returns its sorted version in *O*(*n* log *n*) time (although quick-sort is quicker on average). The *Julia* implementation of the algorithm also keeps track of the *number of comparisons* required. I also wrote this algorithm in *Haskell*.

* **min-cut**: This algorithm takes a graph and returns the size of a *minimal cut* based on repeated applications of *random-cut*, which is based on random contractions of edges. I wrote this in *Julia* again.

* **scc**: This algorithm takes a directed graph and returns its *strongly connected components*. I wrote this in *Python 3* in two different ways: iterative and recursive. The recursive version looks nicer, but it suffers from stack overflow when the graph becomes too large. The iterative version works, but it's a bit slow. I plan to write an efficient recursive implementation in Haskell, which has tail-call optimization (unlike Python).
 
* **dijkstra**: This algorithm takes an undirected graph (whose edges have non-negative lengths) and returns all the shortest paths from some base node. I wrote this *Python 3*.

* **2sum**: This algorithm take a (large) array *A* of integers. It computes how many numbers *t* in the range -10,000 ≤ *t* ≤ 10,000 appear as sums of two integers in *A*. This has been quite a challenge, because the input array *A* provided in the course exercise had 1,000,000 entries. Nevertheless, the final version of this code is surprisingly short and takes about 15 minutes to run on this large input array, using a *pypy3* interpreter. (The first naive version of the code I wrote would've taken no less than a week to finish!)

* **median_maintenance**: This algorithm takes an array *A* of integers and pushes it into two heaps, a max-heap we call *l* (left) and a min-heap *r* (right). The sizes of two heaps *l* and *r* are mutually balanced, which means that we can extract the median of the array *A* in constant time (due to the heap data structure). The output is the sum of all the intermediate medians as the *l* and *r* heaps are populated, modulo 10,000. I wrote this code in *C++*.
