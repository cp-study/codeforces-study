import sys,math
r=sys.stdin.readline
for _ in range(int(r())):
    n=int(r())
    s=r().strip()
    ans=0
    tmp=[]
    cur=0
    for i in range(len(s)):
        if cur==0:
            if s[i]=="L":
                cur-=1
            else:
                cur+=1
        else:
            if cur>0:
                if s[i]=="L":
                    tmp.append(abs(cur))
                    cur=-1
                elif s[i]=="R":
                    cur+=1
            elif cur<0:
                if s[i]=="L":
                    cur-=1
                elif s[i]=="R":
                    tmp.append(abs(cur))
                    cur=1
        if i==len(s)-1 and cur!=0:
            tmp.append(abs(cur))
    if s[0]==s[-1] and len(tmp)>1:
        back=tmp.pop()
        tmp[0]+=back
    if len(tmp)==1:
        print(math.ceil(tmp[0]/3))
    else:
        print(sum([x//3 for x in tmp if x>=3]))
