#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> cords;
vector<vector<int>> adj;
vector<int> visited;
vector<vector<pair<int, int>>> ans;
vector<int> col;
vector<pair<int, int>> temp;
void dfs(int cur, int prev, int color)    {
    if (visited[cur] == true)   {
        return;
    }
    col[cur] = color;
    visited[cur] = true;
    for (int i : adj[cur])  {
        if (i != prev)  {
            dfs(i, cur, color);
        }
    }  
    
}

int main()  {
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    cin >> n >> m;
    cords.resize(n);
    adj.resize(n);
    visited.resize(n);
    col.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cords[i].first = x;
        cords[i].second = y;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i])    {
            dfs(i, -1, cur);
            cur += 1;
        }
    }
    ans.resize(cur);
    for (int i = 0; i < n; i++) {
        ans[col[i]].push_back(cords[i]);
    }
    int sol = INT_MAX;
    for (vector<pair<int, int>> i : ans)   {
        int minx = INT_MAX;
        int miny = INT_MAX;
        int maxx = 0;
        int maxy = 0;
        for (auto j : i)    {
            int curx = j.first;
            int cury = j.second;
            minx = min(minx, curx);
            maxx = max(maxx, curx);
            miny = min(miny, cury);
            maxy = max(maxy, cury);
        }
        //cout << maxx << ' ' << minx << ' ' << maxy << ' ' << miny << endl;
        sol = min(sol, 2 * ((maxx-minx) + (maxy-miny)));
    }
    cout << sol << endl;
}