import sys
from string import ascii_lowercase
r=sys.stdin.readline
for _ in range(int(r())):
    s=r().strip()
    alpa={key:False for key in ascii_lowercase}
    ans=s[0]
    alpa[s[0]]=True
    flg=True
    for i in range(1,len(s)):
        before_ch=s[i-1]
        cur_ch=s[i]
        if alpa[cur_ch]:
            idx=ans.index(cur_ch)
            idx2=ans.index(before_ch)
            if abs(idx2-idx)!=1:
                print("NO")
                flg=False
                break
        else:
            idx=ans.index(before_ch)
            if idx==0:
                ans=cur_ch+ans
                alpa[cur_ch]=True
            elif idx==len(ans)-1:
                ans=ans+cur_ch
                alpa[cur_ch]=True
            else:
                print("NO")
                flg=False
                break
    if flg:
        tmp=[k for k,v in alpa.items() if not alpa[k]]
        print("YES")
        print(ans+''.join(tmp))
    