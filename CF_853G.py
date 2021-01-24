import sys
from collections import defaultdict
r=sys.stdin.readline
N,M=map(int,r().split())
words=defaultdict(int)
tb=['a','b','c','d','e']
st=set()
cnt=0
res=""
def dfs(u):
    global res,cnt
    if u==l:
        if res in st:
            return
        if words[res]>0: cnt+=words[res]
        st.add(res)
        return
    if pattern[u]=='?':
        for i in range(6):
            if i!=5:res+=tb[i]
            dfs(u+1)
            if i!=5:res=res[:-1]
    else:
        res+=pattern[u]
        dfs(u+1)
        res=res[:-1]
for _ in range(N):
    word=r().strip()
    words[word]+=1
for _ in range(M):
    cnt=0
    st.clear()
    pattern=r().strip()
    l=len(pattern)
    res=""
    dfs(0)
    print(cnt)
