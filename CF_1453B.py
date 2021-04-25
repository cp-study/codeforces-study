t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    if n == 2:
        print(0)
    else:
        ans = 0
        dec = max(abs(arr[1]-arr[0]),abs(arr[n-1]-arr[n-2]))
        for i in range(1,n):
            ans += abs(arr[i-1]-arr[i])
        for i in range(1,n-1):
            dec = max(dec,abs(arr[i]-arr[i-1]) + abs(arr[i+1]-arr[i]) - abs(arr[i+1]-arr[i-1]))
        print(ans-dec)
