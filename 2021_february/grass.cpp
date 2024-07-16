#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int N;
bool visited[1000][1000];
 
ll solve() {
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		vector<bool> grid(N,true);
		for (int j = i; j < N; ++j) { 
			int run = 0;
			for (int k = 0; k < N; ++k) {
				grid[k] = grid[k] & visited[j][k];
                if (grid[k] == true)    {
                    run += 1;
                    ans += run;
                } else  {
                    run = 0;
                }
			}
		}
	}
	return ans;
}
 
int main() {
	cin >> N;
	vector<vector<int>> lis(N,vector<int>(N)); 
	for (vector<int>& a: lis) 
		for (int& b: a) cin >> b;
 
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			visited[i][j] = lis[i][j] >= 100;
	ll ans = solve();
 
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j)
			visited[i][j] = lis[i][j] > 100;
	ans -= solve();
 
	cout << ans << "\n";
}
