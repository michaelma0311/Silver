#include <bits/stdc++.h>

using namespace std;

int b, e, p, n, m;
struct st   {
    int dist0;
    int dist1;
    int distn;
};
vector<vector<int>> adj;
vector<st> dist;
vector<bool> visited;
void sdist(int fir, int cur, int prev, int cnt)    {
    //cout << cur << endl;
    visited[cur] = true;
    //cout << cur << endl;
    if (fir == 0)  {
        dist[cur].dist0 = min(dist[cur].dist0, cnt);
    } else if (fir == 1)  {
        dist[cur].dist1 = min(dist[cur].dist1, cnt);
    } else  {
        dist[cur].distn = min(dist[cur].distn, cnt);
    }
    /*if ((fir == 0 || fir == 1) && cur == n-1)   {
        //cout << "DADA" << endl;
        return;
    }
    if ((fir == -1) && (cur == 1 || cur == 0))   {
        //cout << "ADAD" << endl;
        return;
    }
    */
    for (int i : adj[cur])  {
        if (i != prev)  {
            if (visited[i] == true && visited[cur] == true) {
                return;
            }
            sdist(fir, i, cur, cnt+1);
        }
    }
}

int main()  {
    freopen("piggyback.in","r",stdin);
	freopen("piggyback.out","w",stdout);
    cin >> b >> e >> p >> n >> m;
    adj.resize(n);
    dist.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        dist[i].dist0 = INT_MAX;
        dist[i].dist1 = INT_MAX;
        dist[i].distn = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sdist(0, 0, -1, 0);
    fill(visited.begin(), visited.end(), false);
    sdist(1, 1, -1, 0);
    fill(visited.begin(), visited.end(), false);
    sdist(-1, n-1, -1, 0);
    //for (int i = 0; i < n; i++) {
    //    cout << dist[i].dist0 << ' ' << dist[i].dist1 << ' ' << dist[i].distn << endl;
    //}
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int dis0 = dist[i].dist0;
        int dis1 = dist[i].dist1;
        int disn = dist[i].distn;
        ans = min(ans, dis0*b + dis1*e + disn*p);
    }
    cout << ans << endl;
}