#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> lis;
vector<int> wid;
vector<int> cmp;

void dfs(int cur, int prev, int col, int mid)    {
    if (cmp[cur] != -1) {
        return;
    }
    cmp[cur] = col;
    for (auto i : adj[cur])  {
        if (i.first != prev && i.second >= mid)  {
            dfs(i.first, cur, col, mid);
        }
    }
}

bool ok(int mid)    {
    fill(cmp.begin(), cmp.end(), -1);
    int colr = 0;
    for (int i = 0; i < n; i++) {
        if (cmp[i] == -1)   {
            dfs(i, -1, colr, mid);
        }
        colr += 1;
    }
    for (int i : lis)   {
        //cout << mid << ' ' << cmp[i] << ' ' << cmp[lis[i]] << endl;
        if (cmp[i] != cmp[lis[i]])  {
            return false;
        }
    }
    return true;
}

int main()  {
    freopen("wormsort.in","r",stdin);
	freopen("wormsort.out","w",stdout);
    cin >> n >> m;
    lis.resize(n);
    adj.resize(n);
    wid.resize(n);
    cmp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
        lis[i] -= 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    long long lo = 0;
    long long hi = 1e9+1;
    long long ans = -2;
    while (lo <= hi)    {
        long long mid = (lo + hi)/2;
        if (ok(mid))    {
            ans = max(ans, mid);
            lo = mid + 1;
        } else  {
            hi = mid-1;
        }
    }
    if (is_sorted(lis.begin(), lis.end()))    {
        cout << -1 << endl;
    } else  {
        cout << ans << endl;
    }
}