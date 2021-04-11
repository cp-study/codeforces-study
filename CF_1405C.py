for _ in range(int(input())):
    n,k = map(int,input().split())
    s = input()
    
    arr = [-1]*n
    flag = True
    for i in range(n):
        if arr[i%k] == -1:
            if s[i] == '0':
                arr[i%k] = 0
            if s[i] == '1':
                arr[i%k] = 1
        else:
            if s[i] == '0' and arr[i%k] == 1 or s[i] == '1' and arr[i%k] == 0:
                flag = False
                break

    zero = one = 0
    for i in range(k):
        if arr[i] != -1:
            if arr[i] == 0:
                zero+=1
            else:
                one+=1

    if zero > k//2 or one > k//2:
        flag = False
    if flag:
        print("YES")
    else:
        print("NO")
