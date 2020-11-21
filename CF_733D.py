import sys
from itertools import combinations
r = sys.stdin.readline
N = int(r())
edge = dict()
ans = set()
mx = (-1,0)


def get_xy_z(xyz:list):
    res = []
    for i in range(3):
        lst=[]
        tmp=0
        for j in range(3):
            if i == j:
                tmp = xyz[j]
            else:
                lst.append(xyz[j])
        lst.sort()
        res.append((
            tuple(lst), tmp
        ))
        res=list(set(res))
    return res


for i in range(1, N + 1):
    xyz = list(map(int, r().split()))
    ans.add((min(xyz), i))
    
    xy_z=get_xy_z(xyz)

    for pair,z in xy_z:
        if pair not in edge:
            edge[pair]=(z,i)
        else:
            c,idx=edge[pair]
            edge[pair]=(c,idx) if c>z else (z,i)
            lst=list(pair)+[c+z]
            if min(lst)>mx[0]:
                tmp=max(mx[0],min(lst))
                mx=(tmp, (idx,i))

ans = list(ans)
ans.sort(key=lambda x: x[0],reverse=True)
if ans[0][0] > mx[0]:
    print(1)
    print(ans[0][1])
else:
    print(2)
    print(*mx[1])
