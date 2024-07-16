#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int n;
	vector<pair<int, int>> pairs;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pairs.push_back(make_pair(y, x));
	}
	sort(pairs.begin(), pairs.end());
	int ans = 0;
    int lo = 0;
    int hi = n-1;

	while (lo <= hi) {
		int cur = min(pairs[lo].second, pairs[hi].second);
        
		if (lo == hi) {
            cur /= 2;
        }
        int fe;
        fe = pairs[lo].first + pairs[hi].first;
		ans = max(ans, fe);
        //cout << lo << ' ' << hi << ' ' << pairs[lo].second << ' ' << pairs[hi].second << ' ' << cur << endl;
		pairs[lo].second -= cur;
		pairs[hi].second -= cur;
		//cout << "adad" << lo << ' ' << hi << ' ' << pairs[lo].second << ' ' << pairs[hi].second << ' ' << cur << endl;
		if (pairs[lo].second <= 0) {
            lo += 1;
        }
		if (pairs[hi].second <= 0) {
            hi -= 1;
        }
	}
	cout << ans << endl;
}