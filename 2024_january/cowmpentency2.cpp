#include <bits/stdc++.h>
using namespace std;

void solve()    {
    int n, q, c;
	cin >> n >> q >> c;
    vector<int> lis(n);
    vector<int> maxnum(n);
    vector<int> tempo(n);
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
        maxnum[i] = l;
        tempo[i] = lis[i];
        l = max(l, lis[i]);
    }
    vector<pair<int, int>> se(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        se[i] = make_pair(x, y);
    }
    sort(se.begin(), se.end());
    vector<bool> marked(n);
    set<int>
    for (auto i : se)   {
        int s, e;
        s = i.first;
        e = i.second;
    }
}


int main() {
	int t;
	cin >> t;
	for (int _ = 0; _ < t; _++)	{
		solve();
	}
}