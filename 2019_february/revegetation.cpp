#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<long long, bool>>> lis;
long long n, m;
vector<long long> ans;
long long num;
void dfs(long long cur, long long prev) {
    if (ans[cur] != -1) {
        return;
    }
    ans[cur] = 1;
    for (auto i : lis[cur]) {
        if (i.first != prev)    {
            dfs(i.first, cur);
        }
    }
}

int main()  {
    freopen("revegetate.in","r",stdin);
	freopen("revegetate.out","w",stdout);
    cin >> n >> m;
    lis.resize(n);
    for (long long i = 0; i < m; i++) {
        char a;
        long long x, y;
        cin >> a >> x >> y;
        x -= 1;
        y -= 1;
        lis[x].push_back(make_pair(y, (a == 'S')));
        lis[y].push_back(make_pair(x, (a == 'S')));
    }
    ans.resize(n);
    fill(ans.begin(), ans.end(), -1);
    for (long long i = 0; i < n; i++) {
        if (ans[i] == -1)   {
            dfs(i, -1);
            num += 1;
        }
    }
    if (num == 0)   {
        cout << '0' << endl;
    } else  {
        cout << '1';
        for (long long i = 0; i < num; i++)   {
            cout << '0';
        }
        cout << endl;
    }
}