a,b,f,k = map(int,input().split())

tf = a-f
gas = b-f

if gas < 0:
    print(-1)
    exit()

ans = 0
for i in range(k):
    if i%2 == 0:
        if i == k-1:
            if gas < tf:
                gas = b
                ans +=1   
        else:
            if gas < tf*2:
                gas = b
                ans +=1
        if i == k-1:
            gas -= tf
        else:
            gas -= tf*2
        if gas < 0:
            print(-1)
            exit()
    else:
        if i == k-1:
            if gas < f:
                gas = b
                ans +=1   
        else:
            if gas < f*2:
                gas = b
                ans +=1
        if i == k-1:
            gas -= f
        else:
            gas -= f*2
        if gas < 0:
            print(-1)
            exit()
print(ans)
