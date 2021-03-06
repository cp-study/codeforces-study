import sys
r=sys.stdin.readline
for _ in range(int(r())):
    s=r().strip()
    cango=set()
    coord=(0,0)
    for ch in s:
        if ch=='L':
            coord=(coord[0]-1,coord[1])
        if ch=='R':
            coord=(coord[0]+1,coord[1])
        if ch=='D':
            coord=(coord[0],coord[1]-1)
        if ch=='U':
            coord=(coord[0],coord[1]+1)
        cango.add(coord)
    cango.discard((0,0))
    def ck(a,b):
        cur=[0,0]
        for ch in s:
            if ch=='L':
                ncur=[cur[0]-1,cur[1]]
            if ch=='R':
                ncur=[cur[0]+1,cur[1]]
            if ch=='D':
                ncur=[cur[0],cur[1]-1]
            if ch=='U':
                ncur=[cur[0],cur[1]+1]
            if ncur==[a,b]:
                continue
            else:
                cur=ncur
        if cur==[0,0]:
            return True
        return False
    flg=True
    for x,y in cango:
        if ck(x,y):
            print(f'{x} {y}')
            flg=False
            break
    if flg:
        print("0 0")