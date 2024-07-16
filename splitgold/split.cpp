#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, inf = INT_MAX;
int solve(vector<array<int, 2>>& points) {
	sort(points.begin(), points.end());
	vector<int> l(n+1), d(n+1), r(n+1), u(n+1);
	l[n] = d[n] = inf;
	for (int i = n-1; i >= 0; --i) {
		int x = points[i][0], y = points[i][1];
		l[i] = min(x, l[i+1]);
		r[i] = max(x, r[i+1]);
		d[i] = min(y, d[i+1]);
		u[i] = max(y, u[i+1]);
	}
	int one = (r[0] - l[0]) * (u[0] - d[0]);
	int left = 10000000, ri = 0, down = 100000000, up = 0, ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x = points[i][0];
        int y = points[i][1];
		left = min(left, x);
		ri = max(ri, x);
		down = min(down, y);
		up = max(up, y);
		int if_two = ((ri-left) * (up-down)) + ((r[i+1]-l[i+1]) * (u[i+1]-d[i+1]));
		ans = max(ans, one - if_two);
	}
	return ans;
}
signed main() {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	cin >> n;
	vector<array<int, 2>> points(n);
	for (auto& p : points) cin >> p[0] >> p[1];
	int ans = solve(points);
	for (auto& p : points) swap(p[0], p[1]);
	ans = max(ans, solve(points));
	cout << ans;
}
