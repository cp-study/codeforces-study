n = int(input())
arr = [int(x) for x in input().split()]
d = set()
d.add(0)
cur = 0
ans = 0
for i in range(n):
    cur += arr[i]
    if cur in d:
        ans +=1
        d = set()
        d.add(0)
        cur = arr[i]
    d.add(cur)
print(ans)
