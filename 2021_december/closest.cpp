#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, M, N;
	cin >> K >> M >> N;
	vector<pair<int, int>> patches(K + M); 
	for (int i = 0; i < K; ++i)
		cin >> patches[i].first >> patches[i].second;
	for (int i = K; i < K + M; ++i) {
		cin >> patches[i].first;
		patches[i].second = -1;
	}
	sort(begin(patches), end(patches));
	vector<long long> inc;
	int cur = -1;
	long long temp = 0;
	for (int i = 0; i < (int)patches.size(); ++i) {
		if (patches[i].second == -1) {
			if (cur == -1) {
				inc.push_back(temp);
			} else {
				long long sol = 0;	
				long long ans = 0; 
				for (int j = cur + 1, r = cur; j < i; ++j) {
					while (r + 1 < i &&
						   (patches[r + 1].first - patches[j].first) * 2 <
							   patches[i].first - patches[cur].first) {
						sol += patches[++r].second;
					}

					ans = max(ans, sol);
					sol -= patches[j].second;
				}
				assert(2 * ans >= temp);

				inc.push_back(ans);

				inc.push_back(temp - ans);
			}
			cur = i;
			temp = 0;
		} else {
			temp += patches[i].second;
		}
	}

	inc.push_back(temp);
	sort(rbegin(inc), rend(inc));
	inc.resize(N);
	long long ans = 0;
	for (auto val : inc)
		ans += val;
	cout << ans << "\n";
}