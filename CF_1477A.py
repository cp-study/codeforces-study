import sys,math
r=sys.stdin.readline
for _ in range(int(r())):
    n,k=map(int,r().split())
    lst=list(map(int,r().split()))
    st=set(lst)
    if k in st:
        print("YES")
        continue
    lst.sort()
    g=0
    for i in range(len(lst)):
        g=math.gcd(g,lst[i]-lst[0])
    if (k-lst[0])%g==0:
        print("YES")
    else:
        print("NO")