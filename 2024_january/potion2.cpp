#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> lis;
vector<vector<int>> child;
vector<int> ended;
vector<int> runned;
vector<int> tempd;
vector<int> parent;
vector<int> childnum;
vector<vector<int>> adj;
int calc(int cur)   {
    if (child[cur].size() == 0) {
        childnum[cur] = 0;
        return 1;
    }
    for (int i : child[cur])    {
        childnum[cur] += calc(i);
    }
    return childnum[cur];
}
void wip(int cur)   {
    ended[cur] = true;
    if (child[cur].size() == 0) {
        return;
    }
    for (int i : child[cur])    {
        wip(i);
    }
}

void upd(int cur)   {
    int fron = -1;
    if (ended[cur]) {
        return;
    }
    while (cur != -1)   {
        runned[cur] += 1;
        if (runned[cur] >= childnum[cur]) {
            ended[cur] = true;
            fron = cur;
        }
        cur = parent[cur];
    }
    if (fron != -1) {
        wip(fron);
    }
}

void init(int cur, int prev) {
    //cout << cur << ' ' << prev << endl;
    parent[cur] = prev;
    if (prev != -1) {
        child[prev].push_back(cur);
    }
    if (adj[cur].size() == 1 && prev != -1) {
        return;
    }
    for (int i : adj[cur])  {
        if (i != prev)  {
            init(i, cur);
        }
    }
}

int main()  {
    cin >> n;
    tempd.resize(n);
    childnum.resize(n);
    ended.resize(n);
    runned.resize(n);
    child.resize(n);
    parent.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tempd[i];
        tempd[i] -= 1;
    }
    for (int i = 0; i < n-1; i++)   {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init(0, -1);
    //for (int i = 0; i < n; i++) {
    //    cout << i << ' ' << parent[i] << endl;
    //}
    int mi = calc(0);
    for (int i = 0; i < mi; i++)    {
        lis.push_back(tempd[i]);
    }
    long long ans = 0;
    for (int i = 0; i < mi; i++)    {
        int tar = lis[i];
        
        if (ended[tar] == false) {
            upd(tar);
            ans += 1;
        } else  {
            runned[0] += 1;
        }
    }
    cout << ans << endl;
}