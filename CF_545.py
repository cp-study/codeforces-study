import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
if n <= 2:
    print(n)
else:
    ans = 0
    for i in range(1,n-1):
        if arr[i][0] - arr[i][1] > arr[i-1][0]:
            ans +=1
        elif arr[i][0] + arr[i][1] < arr[i+1][0]:
            ans +=1
            arr[i][0] += arr[i][1]
    print(ans+2)
