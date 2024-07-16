s = input()
n = len(s)
prefc = [0 for i in range(n+1)]
prefo = [0 for i in range(n+1)]
prefw = [0 for i in range(n+1)]

for i in range(n):
    prefc[i+1] = prefc[i]
    prefo[i+1] = prefo[i]
    prefw[i+1] = prefw[i]
    if (s[i] == 'C'):
        prefc[i+1] += 1
    elif (s[i] == 'O'):
        prefo[i+1] += 1
    else:
        prefw[i+1] += 1
for i in range(int(input())):
    x, y = map(int, input().split())
    amc = prefc[y]-prefc[x-1]
    amo = prefo[y] - prefo[x-1]
    amw = prefw[y]-prefw[x-1]
    if (amc + amo) % 2 == 1 and (amo + amw) % 2 == 0:
        print('Y', end='')
    else:
        print('N', end='')
print()