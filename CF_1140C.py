import sys
input = sys.stdin.readline
from heapq import heappush,heappop

n,k = map(int,input().split())
arr = []
for i in range(n):
    t,b = map(int,input().split())
    arr.append((b,t))

arr.sort(reverse=True)

ans = 0
Sum = 0
heap = []
for b,t in arr:
    Sum += t
    heappush(heap,t)
    if len(heap) > k:
        Sum -= heappop(heap)
    ans = max(ans,Sum*b)
print(ans)
