import sys
r=sys.stdin.readline

for _ in range(int(r())):
    n=int(r())
    seq=list(map(int,r().split()))
    def isH(i):
        return seq[i]>seq[i-1] and seq[i]>seq[i+1]
    def isV(i):
        return seq[i]<seq[i-1] and seq[i]<seq[i+1]
    def ck(i):
        return isH(i) or isV(i)
    def cklr(i):
        if len(seq)==3:
            return int(ck(i))
        else:
            if i==1:
                return sum(list(map(int,map(ck,[i,i+1]))))
            if i==len(seq)-2:
                return sum(list(map(int,map(ck,[i-1,i]))))
            else:
                return sum(list(map(int,map(ck,[i-1,i,i+1]))))
    if n<3:
        print(0)
    else:
        cnt=0
        for i in range(1,n-1):
            if ck(i):
                cnt+=1
        ans=cnt
        for i in range(1,n-1):
            tmp=seq[i]
            origin=cklr(i)
            seq[i]=seq[i-1]
            left=cklr(i)
            seq[i]=seq[i+1]
            right=cklr(i)
            seq[i]=tmp
            if origin>min(left,right):
                ans=min(ans, cnt-(origin - min(left,right)))
        print(ans)
