lets = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
 
t = int(input())
for test_case in range(t):
    s = input()
    t = input()
 
    becomes = {}
    tof = True
    for i in range(len(s)):
        if s[i] in becomes and becomes[s[i]] != t[i]:
            tof = False
        becomes[s[i]] = t[i]
    if len(set(t)) == 52 and s != t:
        tof = False
 
    answer = 0
    if tof:
        #print("ADADAD")
        ind = {}
        for r in lets:
            if r in becomes and becomes[r] != r:
                ind[becomes[r]] = ind.get(becomes[r], 0) + 1
                answer += 1
        visited = {}
        for r in lets:
            if r not in visited:
                a = r
                while a not in visited:
                    visited[a] = r
                    a = becomes.get(a, a)
                    #print(a, visited[a])
                if a in becomes and a != becomes[a] and visited[a] == r:
                    s = a
                    cycle = True
                    while True:
                        #print(ind, a, ind.get(a, 0), visited[a])
                        visited[a] = 'done'
                        
                        if ind.get(a, 0) > 1:
                            
                            cycle = False
                        a = becomes[a]
                        if a == s:
                            break
                    if cycle:
                        answer += 1
        print(answer)
    else:
        print(-1)