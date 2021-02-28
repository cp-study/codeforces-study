import sys
r=sys.stdin.readline
for _ in range(int(r())):
    N=int(r())
    s=r().strip()
    dpl=[i for i in range(N+1)]
    dpr=[i for i in range(N+1)]
    for i in range(N+1):
        if i==0 or s[i-1]=='R':
            dpl[i]=i
        elif i==1 or s[i-2]=='L':
            dpl[i]=i-1
        else:
            dpl[i]=dpl[i-2]
    for i in range(N,-1,-1):
        if i==N or s[i]=='L':
            dpr[i]=i
        elif i==N-1 or s[i+1] =='R':
            dpr[i]=i+1
        else:
            dpr[i]=dpr[i+2]

    ans=[dpr[i]-dpl[i]+1 for i in range(N+1)]
    print(*ans)