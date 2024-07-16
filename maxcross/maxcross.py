fin = open('maxcross.in')
n, k, b = map(int, fin.readline().split())
pref = [0 for i in range(n+1)]
for i in range(b):
    p = int(fin.readline())
    pref[p] = 1
for i in range(1, n+1):
    pref[i] += pref[i-1]
ans = float('inf')
for i in range(k, n+1):
    ans = min(ans, pref[i]-pref[i-k])
with open('maxcross.out', 'w') as f:
    f.write(str(ans) + '\n')