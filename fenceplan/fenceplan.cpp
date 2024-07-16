#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> x;
vector<int> y;
vector<vector<int>> adj;
vector<bool> visited;

vector<int> net;

void dfs(int cur)   {
    net.push_back(cur);
    visited[cur] = true;
    for (int i : adj[cur])  {
        if (visited[i] == false)    {
            dfs(i); 
        }
    }
}

int main()  {
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    cin >> n >> m;
    x.resize(n);
    y.resize(n);
    adj.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);

    }
    vector<vector<int>> nets;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false)    {
            net.clear();
            dfs(i);
            nets.push_back(net);
        }
    }
    int ans = INT_MAX;

    for (vector<int> netz : nets)  {
        int minx = INT_MAX;
        int maxx = 0;
        int miny = INT_MAX;
        int maxy = 0;
        int per = 0;
        for (int j:netz) {
            minx = min(minx, x[j]);
            maxx = max(maxx, x[j]);
            miny = min(miny, y[j]);
            maxy = max(maxy, y[j]);
            
            
        }
        per = ((maxx-minx)+(maxy-miny))*2;
        ans = min(ans, per);
    }
    cout << ans << endl;
}