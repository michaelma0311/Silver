#include <bits/stdc++.h>

using namespace std;

int main() {
	
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	
	int n; 
    cin >> n;
	
	set<int> bes;
	int els[n];
	
	for (int i = 1; i <= 2 * n; ++i) {
        bes.insert(i);
    }
	
	for (int i = 0; i < n; ++i) {
		cin >> els[i];
		bes.erase(els[i]);
	}
	
	set<int> low;
	set<int> high;
	
	int i = 0;
	for (int card : bes) {
		if (i < n / 2) {
            low.insert(card);
        }   else if (i < n) {
                high.insert(card);
            }   else {
                    break;
                }
		i += 1;
	}
	
	int ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		auto cur = high.upper_bound(els[i]);
		if (cur != high.end()) {
			ans++;
			high.erase(cur);
		}
		else {
			high.erase(high.begin());
		}
	}
	for (int i = n / 2; i < n; ++i) {
		auto cur = low.upper_bound(els[i]);
		if (cur != low.begin()) {
			cur--;
			ans++;
			low.erase(cur);
		}
		else {
			low.erase(prev(low.end()));
		}
	}
	
	cout << ans << "\n";
}