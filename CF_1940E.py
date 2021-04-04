for i in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    brr = arr.copy()
    brr.sort()
    ans = []
    p = brr[0]
    k = 0
    for i in range(1, n):
        if p < brr[i]:
            k = i
        p = p + brr[i]
    for i in range(0, n):
        if brr[k] <= arr[i]:
            ans.append(i + 1)
    print(len(ans))
    print(*ans)
