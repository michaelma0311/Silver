#include <bits/stdc++.h>

using namespace std;

struct p    {
    long long from;
    long long to;
    long long stime;
    long long etime;
};
int n, m;
vector<long long> layover;
vector<pair<pair<long long, long long>, pair<long long, long long>>> visited;
vector<vector<p>> adj;
vector<long long> ans;
vector<pair<long long, long long>> times;
void dfs(int cur, int time) {
    int i = 0;
    while (adj[cur].size() != 0)    {
        long long c, r, d, s;
        c = adj[cur][i].from;
        d = adj[cur][i].to;
        r = adj[cur][i].stime;
        s = adj[cur][i].etime;
        if (r < time + layover[cur])    {
            break;
        } else  {
            ans[d] = s;
            adj[cur].erase(adj[cur].begin());
            dfs(d, s);
        }
    }
}

bool cmp(const p &a, const p &b)    {
    return a.stime < b.stime;
}

int main()  {
    //freopen("mooroute.in","r",stdin);
	//  freopen("mooroute.out","w",stdout);
    cin >> n >> m;
    adj.resize(m+1);
    ans.resize(n+1);
    layover.resize(n+1);
    for (int i = 0; i < m; i++) {
        
        struct p cur;
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        
        a -= 1;
        c -= 1;
        cur.from = a;
        cur.to = c;
        cur.stime = b;
        cur.etime = d;
        //cout << "adadad " << cur.from << ' ' << cur.to << ' ' << cur.stime << ' ' << cur.etime << endl;
        //times[i] = make_pair(b, d);
        adj[a].push_back(cur);
    }
    for (int i = 0; i < n+1; i++)   {
        sort(adj[i].begin(), adj[i].end(), cmp);
        reverse(adj[i].begin(), adj[i].end());
    }
    //cout << "out" << endl;
    for (int i = 0; i < n; i++) {
        cin >> layover[i];
    }
    for (int i = 1; i < n; i++) {
        ans[i] = -1;
    }
    //cout << "adadada" << endl;
    dfs(0, -10);    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}

/*5 9
1 0 2 5
1 0 2 10
1 0 2 6
1 0 3 8
4 7 4 1
4 2 3 3
3 10 2 2
2 4 5 3
2 10 4 0
*/
/*#include <bits/stdc++.h>
using namespace std;

struct p    {
    long long to;
    long long stime;
    long long etime;
};

int main() {
    int N, M;
    cin >> N >> M;
    const int INFTY = 1e9+7;
    vector<vector<p>> orig(N+1);
    for (int i = 0; i < M; i++) {
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        struct p adj;
        adj.to = r;
        adj.stime = d;
        adj.etime = s;
        orig[c].push_back(adj);
    }
    vector<int> layovers(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> layovers[i];
    }
    layovers[1] = 0;
    vector<vector<p>> flights(N+1);
    for (int c = 1; c <= N; c++) {
        for (p temp : orig[c]) {
            long long r = temp.to;
            long long d = temp.stime;
            long long s = temp.etime;
            struct p cur;
            cur.to = r-layovers[c];
            cur.stime = d;
            cur.etime = s;
            flights[c].push_back(cur);
        }
        sort(flights[c].rbegin(), flights[c].rend());
    }
    vector<int> time(N+1, INFTY);
    time[1] = 0;
    vector<int> idx(N+1);
    vector<tuple<int, int, int>> q;
    int qid = 0;
    for (auto [r, d, s] : flights[1]) {
        q.push_back({r, d, s});
    }
    while (qid < q.size()) {
        auto [r, d, s] = q[qid];
        time[d] = min(time[d], s);
        while (idx[d] < flights[d].size() && flights[d][idx[d]].first >= s) {
            q.push_back({flights[d][idx[d]].first, flights[d][idx[d]].second, flights[d][idx[d]].third});
            idx[d]++;
        }
        qid++;
    }
    for (int i = 1; i <= N; i++) {
        if (time[i] != INFTY) {
            cout << time[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
*/