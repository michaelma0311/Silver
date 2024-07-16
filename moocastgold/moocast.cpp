#include <bits/stdc++.h>

using namespace std;

const int r = 1001;
int n;
vector<int> x(r);
vector<int> y(r);
vector<bool> visited(r);
vector<vector<bool>> lis(r, vector<bool>(r, false));
int dfs (int cur) {
	visited[cur] = true;

	int count = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i] || !lis[cur][i]) {
            continue;
        }
		count += dfs(i);
	}

	return (count+1);
}
bool check (long long mid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			lis[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if (dist <= mid) {
                lis[i][j] = true;
            }
		}
	}

	fill(visited.begin(), visited.end(), false);

	int cows = dfs(0);
    //cout << cows << endl;
	return (cows == n);
}

int main()  {
    freopen("moocast.in" , "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    long long lo = 1;
    long long hi = 10000000000;
    long long ans = 10000000000;
    //cout << ans << endl;
    while (lo <= hi)    {
        long long mid = lo + (hi-lo)/2;
        if (check(mid)) {
            hi = mid-1;
            ans = min(ans, mid);
        } else  {
            lo = mid+1;
        }
    }
    cout << ans << endl;
}