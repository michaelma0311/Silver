import bisect
n = int(input())
lis = list(map(int, input().split()))
temp1 = [i for i in range(n)]
temp1.sort(key = lambda x: lis[x])
temp = [0 for i in range(n)]
for i in range(n):
    temp[temp1[i]] = i

nums = sorted(lis)
su = 0
psum = [0 for i in range(n)]
psum[0] = nums[0]
for i in range(n):
    su += (i+1)*nums[i]
    if (i >= 1):
        psum[i] = psum[i-1] + nums[i]
psum.insert(0, 0)
#print(temp, su)
q = int(input())
for i in range(q):
    x, y = map(int, input().split())
    x -= 1
    cur = lis[x]
    soindex = temp[x]
    #print('soin', soindex, cur, x, lis)
    if (cur == y):
        sol = su
    else:
        sol = su - cur*(soindex+1)
        if (cur > y):
            ent = bisect.bisect_left(nums, y)
            tempsum = psum[soindex]-psum[ent]
            sol += tempsum
            sol += y*(ent+1)
        else:
            #print("sol", sol, su)
            ent = bisect.bisect_left(nums, y)-1
            tempsum = psum[ent+1]-psum[soindex+1]
            #print(ent, tempsum, soindex)
            sol -= tempsum
            sol += y*(ent+1)
    print(sol)
    
        
