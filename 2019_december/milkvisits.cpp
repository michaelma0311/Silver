#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> farms;
vector<int> lis;
vector<int> visited;

void dfs(int cur, int prev, int col, int start)    {
    if (farms[cur] != farms[start]) {
        return;
    }
    visited[cur] = true;
    lis[cur] = col;
    for (int i : adj[cur])  {
        if (visited[i] == false)    {
            dfs(i, cur, col, start);
        }
    }
}

int main()  {
    freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
    cin >> n >> m;
    visited.resize(n);
    adj.resize(n);
    farms.resize(n);
    lis.resize(n);
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == 'H')   {
            farms[i] = 1;
        } else  {
            farms[i] = 0;
        }
    }
    for (int i = 0; i < n-1; i++)   {
        int r, c;
        cin >> r >> c;
        r -= 1;
        c -= 1;
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    int color = -1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false)    {
            color += 1;
            dfs(i, -1, color, i);
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int temp;
        temp = 0;
        if (c == 'H')   {
            temp = 1;
        }
        a -= 1;
        b -= 1;
        if (lis[a] != lis[b])   {
            cout << 1;
        } else if (lis[a] == lis[b] && farms[a] == temp)    {
            cout << 1;
        } else  {
            cout << 0;
        }
    }
    cout << endl;

}