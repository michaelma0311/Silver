#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

bool grid[3000][3000]; 
 
int main() {
	int N; cin >> N;
	queue<pair<int,int>> cows_to_place;
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		pair<int,int> p; cin >> p.f >> p.s;
		p.f += 1000, p.s += 1000;
		cows_to_place.push(p);
		auto dfs = [&](int x, int y) { 
			if (!grid[x][y]) return;
			int num_adj = 0;
			for (int d = 0; d < 4; ++d) 
				num_adj += grid[x+dx[d]][y+dy[d]];
			if (num_adj == 3)
				for (int d = 0; d < 4; ++d) {
					pair<int,int> nex{x+dx[d],y+dy[d]};
					if (!grid[nex.f][nex.s])
						cows_to_place.push(nex);
				}
		};
		while (!cows_to_place.empty()) {
			pair<int,int> cur = cows_to_place.front(); 
			cows_to_place.pop();
			if (grid[cur.f][cur.s]) continue;
			++ ans; grid[cur.f][cur.s] = 1;
			dfs(cur.f,cur.s);
			for (int d = 0; d < 4; ++d) 
				dfs(cur.f+dx[d],cur.s+dy[d]);
		}
		cout << ans-i << "\n";
	}
}