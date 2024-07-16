n = int(input())
ans = "R"*n
lis = list(map(int, input().split()))
for i in range(n):
    lis[i] -= 2
for i in reversed(range(n)):
    if (lis[i] == 0):
        ans += 'L'
    else:
        while (lis[i] != 0):
            cur = i-1
            mi = lis[i]
            cnt = 1
            while (lis[cur] != 0 and cur >= 0):
                mi = min(lis[cur], mi)
                cnt += 1
                cur -= 1
            ans += ("L"*cnt+"R"*cnt)*int(mi/2)
            for j in range(cur+1, i+1):
                lis[j] -= mi
        ans += "L"
print(ans)