#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	
	int n, k; 
    cin >> n >> k;
	
	vector<int> diamonds(n);
	for (int i = 0; i < n; i++) {
        int  p;
		cin >> p;
        diamonds[i] = p;
	}
	sort(diamonds.begin(), diamonds.end());
	
	
	vector<int> above(n);
	
	vector<int> below(n); 
	
	int l = 0;
	int r = 0;
	while (r < n) {
		if (diamonds[r] - diamonds[l] <= k) {
			above[l] = r - l + 1;
			below[r] = r - l + 1;
			r++;
		} else {
            l++;
        }
	}
	int ans = 0;
    int am = 0;
	for (int i=1; i<n; i++) {
		am = max(am, below[i-1]);
		ans = max(ans, above[i] + am);
	}
	
	cout << ans;
	return 0;
}