#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);

	int n, t;
	cin >> n >> t;
	int cows[n];

	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}

	int low = 1;
    int hi = n;
	int ans = n;

	while (low <= hi) {
        int mid = low + (hi-low)/2;
		priority_queue<int> que;
		int time = 0;
        int cur = 0;
		
		int len = 0;
		while (len < mid && cur < n) {
			que.push(-cows[cur]);
			len++;
			cur++;
		}
		while (que.size() != 0) {
			time += max(0, -que.top() - time);
			que.pop();
			if (cur < n) {
				que.push(-(cows[cur] + time));
				cur++;
			}

		}

		if (time > t) {
			low = mid + 1;
		} else {
			ans = min(ans, mid);
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}