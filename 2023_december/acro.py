import bisect
n, m, k = map(int, input().split())
lis = []
for i in range(n):
    lis.append(list(map(int, input().split())))
lis = sorted(lis, reverse=True)
weights = [i[0] for i in lis]
nums = [i[1] for i in lis]
dp = [0 for i in range(n+1)]
am = [0 for i in range(n+1)]
for i in range(1, n+1):
    p = n-bisect.bisect_left(weights[::-1], weights[i-1]+k)
    dp[i] = dp[p] + min(am[p], nums[i-1]) + min(m, nums[i-1])-am[p]
    #print(i, p, dp[p], am[p], nums[i-1], weights[i-1], weights[i-1]+k)
    am[i] = max(am[p], min(m, nums[i-1]))
#print(dp, am, weights)
print(dp[n])