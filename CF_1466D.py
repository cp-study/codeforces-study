for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    graph=dict()
    for i in range(1,n+1):
        graph[i]=[]
    for i in range(n-1):
        x,y=map(int,input().split())
        graph[x].append(y)
        graph[y].append(x)
    b=[]
    for i in graph:
        if len(graph[i])!=1:
            for j in range(len(graph[i])-1):
                b.append(a[i-1])
    b.sort(reverse=True)
    s=sum(a)
    print(s,end=' ')
    for i in range(len(b)):
        s+=b[i]
        print(s,end=' ')
    print('')
