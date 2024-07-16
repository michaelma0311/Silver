import bisect
fin = open('closest.in')
n, m, k = map(int, fin.readline().split())
patchescow = []
patchesval = []
for i in range(n):
    x, y = list(map(int, fin.readline().split()))
    patchescow += [x]
    patchesval += [y]
nhoj = []
for i in range(m):
    x = int(fin.readline())
    nhoj += [x]
pref = [0 for i in range(n+1)]
for i in range(1, n+1):
    pref[i] = patchesval[i-1] + pref[i-1]
dp1 = [0 for i in range(m+1)]
dp2 = [0 for i in range(m+1)]
if (nhoj[0] != patchescow[0]):
    dp1[0] = pref[bisect.bisect_left(patchescow, nhoj[0])]
if (nhoj[-1] != patchescow[-1]):
    dp1[-1] = pref[-1] - pref[bisect.bisect_right(patchescow, nhoj[-1])]
for i in range(0, m-1):
    #print(i)
    cur1, cur2 = nhoj[i], nhoj[i+1]
    b1, b2 = bisect.bisect_right(patchescow, cur1), bisect.bisect_left(patchescow, cur2)
    #print(cur1, cur2, b1, b2)
    if (b1 == b2):
        dp2[i] = 0
    else:
        dp2[i] = pref[b2]-pref[b1]
    if (b1 <= m):
        if (nhoj[i] not in patchescow):
            dp1[i+1] = patchesval[b1]
dpans = [0 for i in range(k+1)]
visited = []
for i in range(1, k+1):
    for j in range(m+1):
        #print(j)
        if (j not in visited):
            if (dpans[i-1]+dp1[j] > dpans[i] or dpans[i-2]+dp2[j] > dpans[i]):
                visited += [j]
            dpans[i] = max(dpans[i], dpans[i-1]+dp1[j])
            dpans[i] = max(dpans[i], dpans[i-2]+dp2[j])
    #print(dpans[i])
#print(dpans, dp1, dp2)
print(dpans[-1])
    