n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

lis = set(range(1, n + 1)) - set(a) - set(b)

def max_rotation(cycle_a, cycle_b):
    cur = {val: idx for idx, val in enumerate(cycle_a)}
    temp = [0] * k
    for idx, val in enumerate(cycle_b):
        if val in cur:
            temp[idx - cur[val]] += 1
    return max(temp)

print(len(lis) +
      max(max_rotation(a, b), max_rotation(a, b[::-1])))