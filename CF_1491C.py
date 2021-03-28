import sys
rr=sys.stdin.readline

for _ in range(int(rr())):
    n=int(rr())
    S=list(map(int,rr().split()))
    ans=0
    buf=[0]*(n+2)

    for i in range(n):
        tmp=buf[i]

        if tmp<S[i]-1:
            ans+=S[i]-1-tmp
            tmp+=S[i]-1-tmp
        
        buf[i+1]+=tmp-S[i]+1
        for j in range(i+2,min(n,i+S[i]+1)):
            buf[j]+=1
    print(ans)



