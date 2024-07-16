import bisect
g, n = map(int, input().split())
 
def read():
    x, y, t = map(int, input().split())
    return t, x, y

lis = sorted([read() for _ in range(g)])
ans = 0
 
def check(a, b):
    return (a[1]-b[1])**2+(a[2]-b[2])**2 <= (a[0]-b[0])**2
 
for _ in range(n):
    temp = read()
    pos = bisect.bisect(lis, temp) # first greater
    cur = False
    for y in (pos-1, pos):
        if 0 <= y < g:
            cur |= not check(lis[y], temp)
            
    ans += cur
print(ans)