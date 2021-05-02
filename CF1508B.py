import sys
r=sys.stdin.readline

for _ in range(int(r())):
    n, k = map(int,r().split())
    if (k > 1 << (n-1)):
        print(-1)
        continue
    ans = []
    i=1
    while i<=n:
        l = 0
        while i < n and 1 << (n-i-1) < k:
            #k번째 > 2**(n-i-1)
            k -= 1 << (n-i-1)
            #k에서 2**(n-i-1)를 뺌
            l += 1
            i += 1
        for j in range(i, i-l-1, -1): # i부터 거꾸로 i-l까지 넣어
            ans.append(j)
        i+=1
    print(*ans)