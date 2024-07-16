#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
vector<vector<long long>> adj;
long long n;

void dfs(long long cur, long long prev)  {
    //cout << cur+1 << ' ' << cnt << endl;
    if (adj[cur].size() == 1 && prev != -1)   {
        return;
    }
    long long p = 1;
    long long count = 0;
    long long l = adj[cur].size();
    if (prev == -1) {
        l += 1;
    }
    //cout << l << endl;
    while (p < l) {
        p *= 2;
        count += 1;
    }
    ans += count;
    //cout << "NAS " << ans << endl;
    for (long long i : adj[cur])  {
        if (i != prev)  {
            dfs(i, cur);
        }
    }
}

int main()  {
    //freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
    cin >> n;
    adj.resize(n);
    for (long long i = 0; i < n-1; i++)   {
        long long x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    
    //cout << ans << endl;
    cout << ans + n-1 << endl;
}