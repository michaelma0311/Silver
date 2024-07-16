s = input()
ans = 0
dp = [0 for i in range(4)]
sol = 0
for i in s:
    if (i == 'b'):
        dp[0] += 1
    elif (i == 's'):
        dp[2] += 1
    elif (i=='i'):
        dp[3] += 1
    elif (i == 'e'):
        dp[1] += 1
        tof = True
        for j in range(4):
            cur = dp[j]
            if (j == 0):
                if (cur == 0):
                    tof = False
                    break
            elif (j == 1):
                if (cur < 2):
                    tof = False
                    break
            elif (j == 2):
                if (cur < 2):
                    tof = False
                    break
            else:
                if (cur == 0):
                    tof = False
                    break
        if (tof):
            sol += 1
            for j in range(4):
                if j == 0 or j == 3:
                    dp[j] -= 1
                else:
                    dp[j] -= 2
    print(dp)
    ans += sol
print(ans)
