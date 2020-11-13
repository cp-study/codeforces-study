import sys
import heapq
input = sys.stdin.readline

n = int(input())
data = [[x for x in input().split()] for _ in range(2 * n)]

q = []
result = []

for i in data[::-1]:
    if i[0] == "-":
        heapq.heappush(q, int(i[1]))
    else:
        if q:
            m = heapq.heappop(q)
            result.append(m)
        else:
            print("NO")
            sys.exit()

result = result[::-1]
    
q = []
current = 0
for i in data:
    if i[0] == "-":
        m = heapq.heappop(q)
        if m != int(i[1]):
            print("NO")
            sys.exit()
    else:
        heapq.heappush(q, result[current])
        current += 1

print("YES")
print(*result)
