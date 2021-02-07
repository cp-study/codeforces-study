import sys
read=sys.stdin.readline
for _ in range(int(read())):
    n,m=map(int,read().split())
    program=read().strip()

    pre,cur,mn,mx=[(0,0,0)],0,0,0
    for u in program:
        cur+=1 if u=="+" else -1
        mn,mx=min(mn,cur),max(mx,cur)
        pre.append((cur,mn,mx))

    suf,cur,mn,mx=[(0,0)],0,0,0
    for u in reversed(program):
        cur+=1 if u=='-'else -1
        mn,mx=min(mn,cur),max(mx,cur)
        suf.append((mn-cur,mx-cur))

    for _ in range(m):
        l,r=map(int,read().split())
        cur,mn,mx=pre[l-1]
        mn2,mx2=suf[n-r]
        mn=min(mn,cur+mn2)
        mx=max(mx,cur+mx2)
        print(mx-mn+1)
