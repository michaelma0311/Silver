/*
ID: michael504
LANG: C++
TASK: agrinet
*/
#include <bits/stdc++.h>

using namespace std;

int n, a[105][105], weight[105];
bool visited[105];

int main()  {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    int inf = 1e9;
    cin >> n;
    for (int i = 1; i <= n; i++)    {
        for (int j = 1; j <= n; j++)    {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)    {
        weight[i] = inf;
        visited[i] = false;
    }
    weight[1] = 0;
    visited[1] = true;
    int ans = 0;
    int cur = 1;
    for (int i = 1; i <= n; i++)    {
        for (int j = 1; j <= n; j++)    {
            weight[j] = min(weight[j], a[cur][j]);
        }
        int nxt = -1;
        for (int j = 1; j <= n; j++)    {
            if (visited[j] != true && (nxt == -1 || weight[j] < weight[nxt]))   {
                nxt = j;
            }
        }
        cur = nxt;
        ans += weight[nxt];
        visited[nxt] = true;
    }
    cout << ans << endl;
}