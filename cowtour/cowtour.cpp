/*
ID: michael504
LANG: C++
TASK: cowtour
*/

#include <bits/stdc++.h>

using namespace std;

int n, x[150], y[150];
char s[155];
long double adj[150][150];
long double mdist[150];
long double dist(int i, int j)  {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
long double inf = 1e9;
int main()  {
    freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;
        for (int j = 0; j < n; j++) {
            if (cur[j] == '1')  {
                adj[i][j] = dist(i, j);
            } else  {
                adj[i][j] = inf;
            }
            if (i == j) {
                adj[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    long double ans = inf;
    for (int i = 0; i < n; i++) {
        mdist[i] = -1;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == inf)   {
                continue;
            }
            mdist[i] = max(mdist[i], adj[i][j]);
        }
        for (int j = 0; j < i; j++) {
            if (adj[i][j] != inf)   {
                continue;
            } else  {
                ans = min(ans, mdist[i] + dist(i, j) + mdist[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, mdist[i]);
    }
    cout << fixed << setprecision(6) << ans << endl;
}