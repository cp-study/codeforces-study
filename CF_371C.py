cnt_nb, cnt_ns, cnt_nc = 0, 0, 0
for x in input():
    if x == 'B':
        cnt_nb += 1
    elif x == 'S':
        cnt_ns += 1
    else:
        cnt_nc += 1
nb, ns, nc = map(int, input().split())
pb, ps, pc = map(int, input().split())
r = int(input())
left = 0
right = int(1e13)
while right - left > 1:
    mid = (left + right) // 2
    s = max(0, (mid * cnt_nb - nb) * pb) + max(0, (mid * cnt_ns - ns) * ps) + max(0, (mid * cnt_nc - nc) * pc)
    if s <= r:
        left = mid
    else:
        right = mid
print(left)
