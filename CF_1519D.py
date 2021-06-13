import sys
r=sys.stdin.readline

n=int(r())
a=list(map(int,r().split()))
b=list(map(int,r().split()))

pre = [a[0]*b[0]]
for i in range(1,n):
    pre.append(a[i]*b[i]+pre[i-1])

def sol(l, r, d):
    global ans
    while l >= 0 and r < n:
        d -= (a[l] - a[r]) * (b[l] - b[r])
        ans = max(ans, d)
        l -= 1
        r += 1

ans = pre[-1]
p= pre[-1]
for i in range(n):
    sol(i - 1, i + 1, p)
    sol(i, i + 1, p)
    
print(ans)