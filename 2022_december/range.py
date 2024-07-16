n = int(input())
lis = []
for i in range(n):
    p = list(map(int, input().split()))
    lis += [p]
cur = 0
ans = [0 for i in range(n)]
for i in reversed(range(n-1)):
    def check():
        ma = -float('inf')
        mi = float('inf')
        
        for j in range(i, n):
            
            ma = max(ma, ans[j])
            mi = min(mi, ans[j])
            #print(ma, mi, ans[i], lis[i][j-i], ans, i, j, j-i)
            if (ma-mi != lis[i][j-i]):
                return False
        return True
    ans[i] = ans[i+1]+lis[i][1]
    if (check() == False):
        ans[i] = ans[i+1]-lis[i][1]
print(*ans)