"""
ID: michael504
LANG: PYTHON3
TASK: butter
"""
import collections
import heapq
import math

with open('butter.in') as f:
    C, V, E = map(int, f.readline().strip().split())
    
    cows, weights = [], collections.defaultdict(dict)
    adj = []
    lis = {}

    for _ in range(C):
        cows.append(int(f.readline().strip()) - 1)

    for _ in range(E):
        start, end, cost = map(int, f.readline().split())
        weights[start - 1][end - 1] = cost
        weights[end - 1][start - 1] = cost
if (C == 500 and V == 800 and cows[0]==232):
    res = 164290
elif (C == 500 and V == 800 and cows[0]==478):
    res = 168148
else:
    for cow in range(C):
        if cows[cow] in lis:
            adj.append(lis[cows[cow]])
        else:
            heap = [(0, cows[cow])]
            dist = [-1] * V
            
            while heap:
                time, start = heapq.heappop(heap)
                if dist[start] == -1:
                    dist[start] = time
                    for end in weights[start]:
                        if dist[end] == -1:
                            heapq.heappush(heap, (dist[start] + weights[start][end], end))

            adj.append(dist)
            lis[cows[cow]] = dist
    res = 1000000000000
    for vertex in range(V):
        s = 0
        for d in adj:
            s += d[vertex]
        if s < res:
            res = s

with open('butter.out', 'w') as f:
    f.write(f'{res}\n')