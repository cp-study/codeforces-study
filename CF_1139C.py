n, k = map(int, input().split())
parent = [i for i in range(n + 1)]
cnt = [1 for _ in range(n + 1)]
mod = 10 ** 9 + 7
ans = (n ** k) % mod

def find(target):
    if parent[target] == target:
        return target
    
    parent[target] = find(parent[target])
    return parent[target]

def union(u, v):
    a = find(u)
    b = find(v)

    if cnt[a] < cnt[b]:
        a,b = b,a
    parent[b] = a
    cnt[a] += cnt[b]

for _ in range(1, n):
    u, v, x = map(int, input().split())
    if x == 1:
        continue
    union(u, v)
        
for j in range(1, n + 1):
    if parent[j] == j:
        val = (cnt[j] ** k) % mod
        ans = (ans - val) % mod
print(ans)
