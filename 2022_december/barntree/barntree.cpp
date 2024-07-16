#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> vals;
vector<vector<long long>> adj;
vector<long long> sums;
vector<pair<pair<long long, long long>, long long>> ans;
vector<long long> avg;
vector<long long> kptr;
vector<bool> visited;
long long take_sum(long long cur, long long prev)    {
    long long tot = avg[cur];
    for (long long i : adj[cur])  {
        if (i != prev)  {
            tot += take_sum(i, cur);
        }
    }
    sums[cur] = tot;
    return tot;
}

void dfs(long long cur, long long prev) {
    //cout << cur << endl;
    if (adj[cur].size() == 1 && prev != -1)   {
        if (kptr[cur] < 0)  {
            //cout << "ada " << cur << ' ' << prev << ' ' << kptr[cur] << ' ' << kptr.size() << endl;
            // cout << "ADADA" << endl;
            long long de = kptr[cur];
            ans.push_back(make_pair(make_pair(prev, cur), de*-1));
            //cout << "cur " << cur << endl;
            kptr[prev] += de;
            kptr[cur] = 0;
            //cout << "ada " << cur << ' ' << prev << ' ' << kptr[cur] << ' ' << adj[cur].size() << endl;
        } else if (kptr[cur] > 0)    {
            //cout << "end???" << endl;
            ans.push_back(make_pair(make_pair(cur, prev), kptr[cur]));
            kptr[prev] += kptr[cur];
            kptr[cur] = 0;
        }
        return;
    }
    vector<long long> temp;
    for (long long i : adj[cur])  {
        if (i != prev)  {
            if (sums[i] >= 0)   {
                dfs(i, cur);
            } else  {
                temp.push_back(i);
            }
        }
    }
    for (long long i : temp)  {
        ans.push_back(make_pair(make_pair(cur, i), sums[i]*-1));
        kptr[cur] += sums[i];
        kptr[i] -= sums[i];
        
        dfs(i, cur);
    }
    if (kptr[cur] > 0)  {
        //cout << "end? " << cur << ' ' << prev  << endl;
        ans.push_back(make_pair(make_pair(cur, prev), kptr[cur]));
        kptr[prev] += kptr[cur];
        kptr[cur] = 0;
        //cout << "ADADAD" << endl;
        
    }
}

int main()  {
    //freopen("barntree.in","r",stdin);
    //freopen("barntree.out","w",stdout);
    cin >> n;
    vals.resize(n+1);
    adj.resize(n+1);
    sums.resize(n+1);
    avg.resize(n+1);
    kptr.resize(n+1);
    visited.resize(n+1);
    for (int i = 0; i < n+1; i++)   {
        visited[i] = false;
    }
    long long ax = 0;
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        ax += vals[i];
    }
    long long su = ax/n;
    //cout << su << endl;
    for (int i = 0; i < n; i++) {
        avg[i] = vals[i]-su;
        if (avg[i] > 0) {
        }
        kptr[i] = avg[i];
    }
    for (int i = 0; i < n-1; i++)   {
        long long x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sums[0] = take_sum(0, -1);
    dfs(0, -1);
    cout << ans.size() << endl;
    for (auto i : ans)  {
        cout << i.first.first+1 << ' ' << i.first.second+1 << ' ' << i.second << endl;
    }
}