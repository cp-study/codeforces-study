import sys
r=sys.stdin.readline
def lsb(x):
    return x & (-x)
for _ in range(int(r())):
    u,v=map(int,r().split())
    if u>v:
        print("NO")
    else:
        can = True
        while v > 0:
            if lsb(v) < lsb(u) or u == 0:
                can = False
                break
            u -= lsb(u)
            v -= lsb(v)
        print("YES" if can else "NO")
