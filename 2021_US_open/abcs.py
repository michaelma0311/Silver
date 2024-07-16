for _ in range(int(input())):
    n = int(input())
    lis = list(map(int, input().split()))
    lis = sorted(lis)
    nums = set()
    nums.add(lis[0])
    for i in range(1, n):
        nums.add(lis[i])
        for j in range(i, n):
            nums.add(lis[j]-lis[j-i])

    ans = 0
    alr = []  # Convert "alr" list to a set
    for i in nums:
        for j in nums:
            for k in nums:
                temp = [i, j, k]
                temp = sorted(temp)
                if temp in alr:
                    continue
                alr += [temp]  # Convert "alr" list to a set of tuples
                visited = set()  # Convert "visited" list to a set
                cur = 0
                if (i in lis and i not in visited):
                    visited.add(i)
                    cur += 1
                if (j in lis and j not in visited):
                    visited.add(j)
                    cur += 1
                if (k in lis and k not in visited):
                    visited.add(k)
                    cur += 1
                if (i+j in lis and i+j not in visited):
                    visited.add(i+j)
                    cur += 1
                if (i+k in lis and i+k not in visited):
                    visited.add(i+k)
                    cur += 1
                if (j+k in lis and j+k not in visited):
                    visited.add(j+k)
                    cur += 1
                if (i+j+k in lis and i+j+k not in visited):
                    visited.add(i+j+k)
                    cur += 1
                if cur >= n:
                    ans += 1
    print(ans)