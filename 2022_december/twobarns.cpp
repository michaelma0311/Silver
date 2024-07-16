#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[], vector<int> adj[], int cur, int comp[], int count)    {
    //cout << cur << endl;
    comp[cur] = count;
    adj[count].push_back(cur);
    for (int i = 0; i < graph[cur].size(); i++) {
        if (comp[graph[cur][i]] == -1)  {
            dfs(graph, adj, graph[cur][i], comp, count);
        }
    }
}

unsigned long long calc(int from, int to, vector<int> lis[]) {
    unsigned long long x, y, sol = (unsigned long long) - 1;
    if (from == to) {
        return 0;
    }
    for (int i = 0; i < lis[from].size(); i++)  {
        x = (unsigned long long) - 1;
        y = (unsigned long long) - 1;
        int cur = (upper_bound(lis[to].begin(), lis[to].end(), lis[from][i]) - lis[to].begin());
        if (cur < lis[to].size())   {
            x = 1LL * (lis[to][cur] - lis[from][i]) * (lis[to][cur] - lis[from][i]);
        }
        if (cur > 0)    {
            y = 1LL * (lis[to][cur-1] - lis[from][i]) * (lis[to][cur-1] - lis[from][i]);
        }
        sol = min(sol, min(x, y));
    }
    return sol;
}
int main()  {
    int t, n, m;
    cin >> t;
    for (int l = 0; l < t; l++) {
        cin >> n >> m;
        int comp[n];
        vector<int> graph[n];
        vector<int> adj[n];
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for (int i = 0; i < n; i++) {
            comp[i] = -1;
        }
        int am = 0;
        for (int i = 0; i < n; i++) {
            if (comp[i] == -1)  {
                //cout << "times" << endl;
                dfs(graph, adj, i, comp, am++);
            }
        }
        //cout << am << endl;
        for (int i = 0; i < am; i++)    {
            sort(adj[i].begin(), adj[i].end());
        }
        unsigned long long ans = (unsigned long long) - 1;
        for (int i = 0; i < am; i++)    {
            ans = min(ans, calc(i, 0, adj) + calc(i, comp[n-1], adj));
        }
        cout << ans << endl;
    }
}