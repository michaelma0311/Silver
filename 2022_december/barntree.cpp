#include <bits/stdc++.h>
using namespace std;
const int r = 200005;
struct p {
    int from;
    int to;
    long long dist;
};
long long lis[r];
long long su[r];
vector<vector<int>> adj;
vector<p> ans;
long long calc(int cur, int prev)   {
    long long am = lis[cur];
    for (int i : adj[cur])   {
        if (i != prev)  {
            am += calc(i, cur);
        }
    }
    su[cur] = am;
    return am;
}

void doing(int cur, int prev)   {
    //cout << cur << endl;
    for (int i : adj[cur])  {
        if (i != prev && su[i] > 0) {
            doing(i, cur);
        }
    }

    for (int i : adj[cur])  {
        if (i != prev && su[i] <= 0)    {
            if (su[i] < 0) {
                ans.push_back({cur, i, -su[i]});
            }
            doing(i, cur);
        }
    }
    if (cur != 1 && su[cur] > 0)    {
        ans.push_back({cur, prev, su[cur]});
    }
}

int main()  {
    int n;
    cin >> n;
    adj.resize(n+1);
    long long tot = 0;
    for (int i = 1; i <= n; i++)    {
        cin >> lis[i];
        tot += lis[i];
    }
    long long avg = tot/n;
    for (int i = 1; i <= n; i++)    {
        lis[i] -= avg;
    
    }
    for (int i = 0; i < n-1; i++)   {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    calc(1, -1);
    doing(1, -1);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)    {
        p cur = ans[i];
        cout << cur.from << ' ' << cur.to << ' ' << cur.dist << endl;
    }
}