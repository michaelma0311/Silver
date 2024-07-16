#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int>> vids[5001];
vector<bool> visited(5001);
int ans;

void dfs (int cur, int k)  {
    visited[cur] = true;
    for (auto i : vids[cur])    {
        if (visited[i.first] == true)   {
            continue;
        }
        if (i.second >= k) {
            ans += 1;
            dfs(i.first, k);
        }
    }
}
int main()  {
    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vids[a].push_back({b, c});
		vids[b].push_back({a, c});
	}
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        ans = 0;
        fill(visited.begin(), visited.end(), 0);
        dfs(v, k);
        cout << ans << endl;
    }
    
}