def solve_min(needs_pos, pos): #positive slope case
    pos.sort()
 
    def ok(min_y):
        max_slope = []
        for x, y in needs_pos:
            max_slope.append((y - min_y) // x) # calculate what the max slope can be for each vertex
        max_slope.sort()
        return all(a <= b for a, b in zip(pos, max_slope)) # check if these slopes are possible
 
    min_y = min(y for x, y in needs_pos)
    hi = min_y
    lo = min_y - pos[-1] * max(x for x, y in needs_pos)
    assert ok(lo)
    while lo < hi: # binary search over minimum y-intercept
        mid = (lo + hi + 1) // 2
        if ok(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo
 
def solve_max(needs_neg, neg): # negative slope case
    return -solve_min([(x, -y) for x, y in needs_neg], [-s for s in neg]) # convert this to a positive slope case
 
def solve():
    N, x1 = map(int, input().split())
    with_x1 = []
    needs_pos = []
    needs_neg = []
    for _ in range(N):
        y1, y2, x2 = map(int, input().split())
        with_x1.append(y1)
        with_x1.append(y2)
        needs_pos.append((x2, y1))
        needs_neg.append((x2, y2))
    slopes = list(map(int, input().split()))
    assert len(slopes) == 4*N
    neg, pos = [], []
    for s in slopes:
        if s < 0:
            neg.append(s)
        else:
            pos.append(s)
    if len(neg) < N or len(pos) < N:
        print(-1)
        return
    with_x1.sort()
    for y in with_x1: # split leftmost vertices into negative and positive slopes
        if len(needs_neg) < len(neg):
            needs_neg.append((x1, y))
        else:
            needs_pos.append((x1, y))
    assert len(needs_neg) == len(neg)
    assert len(needs_pos) == len(pos)
    # solve for upper and lower bounds of range
    y_min = solve_min(needs_pos, pos)
    y_max = solve_max(needs_neg, neg)
    print(y_max - y_min)
 
T = int(input())
for _ in range(T): solve()