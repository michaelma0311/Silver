/*
ID: michael504
LANG: C++
TASK: comehome
*/

#include <bits/stdc++.h>

using namespace std;
    const int N = 52;
    const int inf = 1e9;
    static int p;
    vector<vector<int>> lis(N, vector<int>(N, inf));
vector<int> dist(N, inf);
void ok(vector<vector<int>> &lis, vector<int> &dist, int cur, int N) {
    vector<bool> visited(N, false);
    dist[cur] = 0;
    while (true) {
        visited[cur] = true;
        for (int i = 0; i < N; i++) {
            if (lis[cur][i] == INT_MAX) continue;
            dist[i] = min(dist[i], dist[cur] + lis[cur][i]);
        }
        int minDist = INT_MAX;
        int idx = -1;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                idx = i;
            }
        }
        if (idx == -1) break;
        cur = idx;
    }
}
int check(char a)   {
    if (a >= 'a' && a <= 'z')   {
        return a-'a';
    }
    return a-'A'+26;
}

int main()  {
    freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
    
    cin >> p;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                lis[i][j] = 0;
            } else  {
                lis[i][j] = inf;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        char x, y;
        int d;
        cin >> x >> y >> d;
        lis[check(x)][check(y)] = min(lis[check(x)][check(y)], d);
        lis[check(y)][check(x)] = min(lis[check(y)][check(x)], d);
    }
    ok(lis, dist, N-1, N);
    int ans = inf;
    int cur;
    for (int i = 26; i < N-1; i++) {
        if (ans > dist[i])  {
            ans = dist[i];
            cur = i;
        }
    }
    cout << char('A'+cur-26) << ' ' << ans << endl;
}