#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> adj;
int main()  {
    freopen("planting.in","r",stdin);
	freopen("planting.out","w",stdout);
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x] += 1;
        adj[y] += 1;
    }
    int ma = 0;
    for (int i : adj)   {
        ma = max(i, ma);
    }
    cout << ma+1 << endl;
}