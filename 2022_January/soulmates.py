for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [n]
    b = [m]
    while (n > 1):
        if (n%2 == 1):
            n += 1
        else:
            n /= 2
        a += [int(n)]
    while (m > 1):
        if (m%2 == 1):
            m -= 1
        else:
            m /= 2
        b += [int(m)]
    a += [1]
    b += [1]
    #print(a, b)
    ans = float('inf')
    for i in range(len(a)):
        for j in range(len(b)):
            if (b[j] >= a[i]):
                #print(b[j], a[i], i, j,b[j]-a[i] + i + j )
                ans = min(ans, b[j]-a[i] + i + j)
    print(ans)