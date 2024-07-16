'''
ID: michael504
LANG: PYTHON3   
TASK: money
'''

fin = open('money.in', 'r')
v, n = map(int, fin.readline().split())
a = []
for i in range(n)
dp = [0 for i in range(10001)]
dp[0] = 1
for i in range(v):
    for j in range(n+1):
        print(i, len(a))
        if (j+a[i] <= n):
            dp[a[i]+j] += dp[j]
with open('money.out', 'w') as f:
        f.write(str(dp[n]) + '\n')