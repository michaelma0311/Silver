#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> ivals(N);
	for (auto &ival : ivals)
		cin >> ival.first >> ival.second;
	vector<int64_t> win_start(2 * M + 1), win_end(2 * M + 1);
	for (auto [a_i, b_i] : ivals)
		for (auto [a_j, b_j] : ivals) {
			++win_start.at(a_i + a_j);
			++win_end.at(b_i + b_j);
		}
	int64_t win_count = 0;
	for (int i = 0; i <= 2 * M; ++i) {
		win_count += win_start.at(i);
		cout << win_count << "\n";
		win_count -= win_end.at(i);
	}
}