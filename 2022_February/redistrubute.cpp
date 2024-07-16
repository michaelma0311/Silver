#include <bits/stdc++.h>
using namespace std;

int n;
const int r = 1001;
bool adj[r][r];
vector<int> lis[r];

void dfs(int fr, int to) {
	if (adj[fr][to] == true)    {
		return;
    }
	adj[fr][to] = true;
	for (int i : lis[to])    {
		dfs(fr, i);
    }
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		lis[i].resize(n);
		for (int j = 0; j < n; j++) {
            int cur;
            cin >> cur;
            lis[i][j] = cur;
        }
		while (lis[i].back() != i)    {
			lis[i].pop_back();
        }
	}
	for (int i = 0; i < n; i++)    {
		dfs(i+1, i+1);
    }

	for (int i = 1; i <= n; i++)    {
		for (int j : lis[i])  {
			if (adj[j][i]) {
				cout << j << endl;
				break;
			}
        }
    }
}