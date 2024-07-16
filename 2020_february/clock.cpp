#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> lis;

int dfs(int cur, int prev)  {
    //cout << cur << ' ' << lis[cur] << endl;
    int p = lis[cur];
    for (int i : adj[cur])    {
        if (i != prev)  {
            
            p += dfs(i, cur);
        }
    }
    p %= 12;
    return (12-p) % 12;
}

int main()  {
    freopen("clocktree.in","r",stdin);
    freopen("clocktree.out","w",stdout);
    int n;
    cin >> n;
    lis.resize(n+1);
    for (int i = 1; i <= n; i++)    {
        cin >> lis[i];
    }
    adj = vector<vector<int>>(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //cout << "hi" << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int temp = dfs(i, -1);
        if (temp == 11 || temp == 0) {
            ans += 1;
        }
    }
    cout << ans << endl;
}