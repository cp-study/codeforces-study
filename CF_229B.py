import sys
from heapq import *
r=sys.stdin.readline

n,m = map(int,r().split())
g=[[] for _ in range(n+1)]
for _ in range(m):
    a,b,c=map(int,r().split())
    g[a].append((b,c))
    g[b].append((a,c))
times=[[]]
for _ in range(n):
    times.append(list(map(int,r().split()))[1:])

INF = sys.maxsize
dist = [INF]*(n+1)
dist[1]=0
q=[(0,1)]

while q:
    d,idx = heappop(q)
    if d !=dist[idx]:
        continue
    cur = dist[idx]
    for i in times[idx]:
        if i==cur:
            cur+=1
    for e,cost in g[idx]:
        if dist[e] > dist[idx]+cost:
            dist[e] = min(dist[e], cur+cost)
            heappush(q,(dist[e],e))
print(dist[n] if dist[n]!=INF else -1)

