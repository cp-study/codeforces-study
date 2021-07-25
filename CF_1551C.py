t = int(input())
for i in range(t):
    n = int(input())
    arr = []
    for j in range(n):
        s = input()
        arr.append(s)
    alpha = ['a','b','c','d','e']
    a = []
    b = []
    c = []
    d = []
    e = []
    res = []
    for j in alpha: #a,b,c,d,e
        for k in arr:
            score = 0
            for l in k:
                if l == j:
                    score +=1
                else:
                    score -=1
            if j =='a':
                a.append(score)
            elif j == 'b':
                b.append(score)
            elif j == 'c':
                c.append(score)
            elif j == 'd':
                d.append(score)
            else:
                e.append(score)
        a = sorted(a,reverse=True)
        b = sorted(b,reverse=True)
        c = sorted(c,reverse=True)
        d = sorted(d,reverse=True)
        e = sorted(e,reverse=True)
    Sum = 0
    count = 0
    for j in range(0,len(a)):
        if Sum + a[j] == 0:
            break
        if Sum + a[j] >= 0:
            Sum += a[j]
            count +=1
        else:
            break
    res.append(count)
    Sum = 0
    count = 0
    for j in range(0,len(b)):
        if Sum + b[j] == 0:
            break
        if Sum + b[j] >= 0:
            Sum += b[j]
            count +=1
        else:
            break
    res.append(count)
    Sum = 0
    count = 0
    for j in range(0,len(c)):
        if Sum + c[j] == 0:
            break
        if Sum + c[j] >= 0:
            Sum += c[j]
            count +=1
        else:
            break
    res.append(count)
    Sum = 0
    count = 0
    for j in range(0,len(d)):
        if Sum + d[j] == 0:
            break
        if Sum + d[j] >= 0:
            Sum += d[j]
            count +=1
        else:
            break
    res.append(count)
    Sum = 0
    count = 0
    for j in range(0,len(e)):
        if Sum + e[j] == 0:
            break
        if Sum + e[j] >= 0:
            Sum += e[j]
            count +=1
        else:
            break
    res.append(count)
    print(max(res))
