n,m=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
prefixSum = arr
for i in range(1,n):
	prefixSum[i] += prefixSum[i-1]
ans = [0 for _ in range(n)]
for i in range(m):
    ans[i] = prefixSum[i]
for i in range(m,n):
    ans[i] = prefixSum[i] + ans[i-m]
for i in ans:
    print(i,end=' ')
