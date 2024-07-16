/*
ID: michael504
LANG: C++
TASK: fence
*/
#include <bits/stdc++.h>

using namespace std;
int f;
int adj[501][501];
int lis[501];
vector<int> ans;

void dfs(int cur) {
    for (int i = 1; i <= 500; i++) {
        while (adj[cur][i] > 0) {
            adj[cur][i]--;
            adj[i][cur]--;
            dfs(i);
        }
    }
    ans.push_back(cur);
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    cin >> f;
    memset(adj, 0, sizeof adj);
    for (int i = 0; i < f; i++) {
        int a, b; cin >> a >> b;
        adj[a][b]++; adj[b][a]++;
        lis[a]++;
        lis[b]++;
    }
    bool tof = false;
    for (int i = 1; i <= 500; i++) {
        if (lis[i] % 2 == 1) {
            dfs(i);
            tof = true;
            break;
        }
    }
    if (!tof) {
        dfs(1);
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << endl;
    }
    return 0;
}