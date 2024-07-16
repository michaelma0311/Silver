#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj;
vector<pair<int, int>> cycles;
vector<bool> visited;
int first, last;

long long calc(int x, int y)  {
    return x*x+y*y;
}

void dfs(int cur, int prev) {
    if (visited[cur])   {
        return;
    }
    visited[cur] = true;
    last = max(last, cur);
    for (int i : adj[cur])  {
        dfs(i, cur);
    }
}

void solve()    {
    
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    cycles.clear();
    visited.clear();
    visited.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && adj[i].size() >= 1)    {
            first = i;
            last = 0;
            dfs(i, -1);
            cycles.push_back(make_pair(first, last));
        }
    }
    long long ans = 1e9;
    for (auto i : cycles)   {
        cout << i.first << "adada " << i.second << endl;
    }
    if (cycles.size() == 0) {
        int z = (n-1)/2;
        ans = calc(z, n-1-z);
    } else if (cycles[0].first == 0 && cycles[1].second == n-1)  {
        int z1 = cycles[0].second;
        int z2 = cycles[1].first;
        //cout << z1 << ' ' << z2 << endl;
        int temp = abs(z2-z1)/2;
        ans = calc(temp, z2-z1-temp);
    } else if ((cycles[0].first == 0 && cycles.size() == 1) || (cycles[1].second == n-1 && cycles.size() == 1))  {
        if (cycles[0].first != 0)  {
            int z = cycles[0].first;
            int temp = z/2;
            ans = calc(temp, z-temp);
        } else  {
            int z = cycles[0].second;
            int temp = (n-1-z)/2;
            ans = calc(temp, n-1-z-temp);

        }
    } else  {
        //cout << "ADADA" << endl;
        int start = 0;
        int end = n-1;
        int s = 0;
        int e = cycles.size();
        if (cycles[0].first == 0)   {
            start = cycles[0].second;
            s = 1;
        }
        if (cycles[cycles.size()-1].second == n-1)  {
            end = cycles[cycles.size()-1].first;
            e = cycles.size()-1;
        }
        for (int i = s; i < e; i++) {
            int cur1 = cycles[i].first;
            int cur2 = cycles[i].second;
            //cout << cur1 << ' ' << cur2 << endl;
            ans = min(ans, calc(cur1-start, end-cur2));

        }
    }
    cout <<"ans " <<  ans << endl;

}

int main()  {
    freopen("twobarns.in","r", stdin);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
    }
}