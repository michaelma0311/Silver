#include <bits/stdc++.h>

using namespace std;

bool con[200][200];
vector<bool> visited;
int n;

int dfs(int cur)    {
    visited[cur] = true;
    int am = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == true || con[cur][i] == false) {
            continue;
        }
        visited[i] = true;
        am += dfs(i)+1;
    }
    return am;
}

int main()  {
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> p[i];
	}
    int dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)   {
            dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist <= p[i]*p[i])  {
                con[i][j] = true;
            }

        }
    }
    visited.resize(n, false);
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = dfs(i) + 1;
        ans = max(ans, j);

    }
    cout << ans << endl;

}
