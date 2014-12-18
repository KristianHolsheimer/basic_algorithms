import time

with open('2sum_example.txt', 'r') as f:
    A = set([])
    for n in f:
        A.add(int(n))

ts = set()

print(len(A))

while A:
    x = A.pop()
    ts.update([t for t in range(-10000,10001) if t-x in A])

print('count = {}'.format(len(ts)))


## expected output from "2sum_example.txt":
## count = 5
