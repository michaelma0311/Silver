n, m = map(int, input().split())
inc = [0 for i in range(2*m)]
dec = [0 for i in range(2*m)]
ans = [0 for i in range(2*m)]
for i in range(n):
    x, y = map(int, input().split())
    inc[x] += 1
    dec[y] += 1
ans[0] += inc[0] - dec[0]
for i in range(1, 2*m):
    ans[i] = ans[i-1] + inc[i]-dec[i]
print(ans)