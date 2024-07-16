
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, bool>>> adj(n);
	
	for (int i = 0; i < m; i++) {
		char type;
		int u, v;
		cin >> type >> u >> v;
		u -= 1;
        v -= 1;
		adj[u].push_back({v, type == 'S'});
		adj[v].push_back({u, type == 'S'});
	}

	int num = 0;
	bool imp = false;
	vector<int> ans(n, -1);

	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			num += 1;

			
			queue<pair<int, bool>> next;
			next.push({i, true});

			while (next.size() != 0) {
				pair<int, bool> curl = next.front();
				next.pop();

				ans[curl.first] = curl.second;
				for (pair<int, bool> p : adj[curl.first]) {
                    bool type;
                    if (p.second == true)   {
                        type = curl.second;
                    } else  {
                        type = !curl.second;
                    }
					
					if (ans[p.first] == -1) {
						next.push({p.first, type});
					} else if (ans[p.first] != type) {
						imp = true;
						break;
					}
				}
			}
		}
	}


	if (imp) {
		cout << 0 << endl;
	} else {
		cout << 1;
		for (int i = 0; i < num; i++) {
			cout << 0;
		}
		cout << endl;
	}
}
