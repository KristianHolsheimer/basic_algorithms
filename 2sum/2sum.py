#!/usr/bin/pypy3

# load array A as a Python set:
with open('2sum_example.txt', 'r') as f:
    A = set()
    for n in f:
        A.add(int(n))


# initialize the set of t's:
ts = set()

# for each element in A, check which t's satisfy "t-x in A"
while A:
    x = A.pop()
    ts.update(t for t in range(-10000,10001) if t-x in A)


# count the number of such t's:
print(len(ts))


# expected output from "2sum_example.txt":
# 5
