import sys,bisect
r=sys.stdin.readline

for _ in range(int(r())):
    n,m,a,b=map(int,r().split())
    f=list(map(int,r().split()))

    canDrop=abs(a-b)-1
    if canDrop < 1:
        print(0)
        continue
    ans=0
    f.sort()
    if a>b:
        dist=n-b-1
    else:
        dist=b-2
    for i in range(m-1,-1,-1):
        if f[i]>dist:
            continue
        else:
            ans+=1
            dist-=1
            if ans==canDrop:
                break
    print(ans)