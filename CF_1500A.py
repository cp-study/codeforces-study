import sys
from collections import defaultdict
r=sys.stdin.readline
n = int(input())
a = list(map(int, r().split()))
d = {}
for i in range(n):
	for j in range(i):
		# print(d)
		if(a[i]+a[j] in d):
			ii,jj = d[a[i]+a[j]]
			if(len(set([i,j,ii,jj]))==4):
				print('YES')
				print(i+1,j+1,ii+1,jj+1)
				exit(0)
		else:
			d[a[i]+a[j]] = (i,j)
print('NO')