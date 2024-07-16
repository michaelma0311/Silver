#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
#define all(x) begin(x), end(x)

vector<int> a, v;
vector<vector<int>> child;
vector<bool> done;

void mark_as_done(int x) {
	if (done[x]) return;
	//cout << x << endl;
	done[x] = true;
	for (int c : child[x]) mark_as_done(c);
}

int solve(int start) {
	int x = start, y = start;
	do {
		x = a[x], y = a[a[y]];
	} while (x != y);
	int min_along_cycle = INT_MAX;
	do {
		min_along_cycle = min(min_along_cycle, v[x]);
		x = a[x];
	} while (x != y);
	mark_as_done(x);
	return min_along_cycle;
}

int main() {
	int n;
	cin >> n;
	a.resize(n + 1);
	v.resize(n + 1);
	child.resize(n + 1);
	int64_t ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> v[i];
		ans += v[i];
		child[a[i]].push_back(i);
	}
	done.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		if (!done[i]) ans -= solve(i);
	cout << ans << "\n";
}