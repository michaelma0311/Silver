#include <bits/stdc++.h>

using namespace std;



int n, m;
const int r = 3000;
vector<int> visited(r);
vector<vector<int>> adj(r);
vector<int> close(r);
int am = 0;


void dfs(int cur)    {
    //cout << cur << endl;
    if (visited[cur] == true || close[cur] == true)   {
        return;
    }
    am += 1;
    visited[cur] = true;
    for (auto i : adj[cur]) {
        dfs(i);
    }
}

int main()  {
    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
    cin >> n >> m;
    int p = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> closing(n);
    for (int i = 0; i < n; i++) {
        cin >> closing[i];
    }
    dfs(1);
    if (am == p)    {
        cout << "YES" << endl;
    } else  {
        cout << "NO" << endl;
    }

    for (int i = 0; i < n-1; i++)   {
        fill(visited.begin(), visited.end(), false);
        p -= 1;
        am = 0;
        close[closing[i]] = true;
        dfs(closing[n-1]);
        if (am == p)    {
            cout << "YES" << endl;
        } else  {
            cout << "NO" << endl;
        }
    }
}
