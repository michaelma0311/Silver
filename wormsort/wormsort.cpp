#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MX = 1e5;
vector<pair<int, int>> pairs[MX];
vector<int> bef(MX), component(MX);

void dfs(int cur, int lab, int minw)    {
    component[cur] = lab;
    for (auto i : pairs[cur])   {
        if (i.second < minw || component[i.first] != -1)    {
            continue;
        }
        dfs(i.first, lab, minw);
    }
}

bool ok(int minw)   {
    fill(component.begin(), component.end(), -1);
    int lab = -1;
    for (int i = 0; i < n; i++) {
        if (component[i] != -1) {
            continue;
        }
        lab += 1;
        dfs(i, lab, minw);
    }
    for (int i = 0; i < n; i++) {
        if (component[i] != component[bef[i]])  {
            return false;
        }
    }
    return true;
}


int main()  {
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bef[i] = a-1;
    }
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        pairs[a-1].push_back(make_pair(b-1, w));
        pairs[b-1].push_back(make_pair(a-1, w));

    }
    int ans = -1;
    int lo = 1;
    int hi = 1e9;
    int top = hi;
    while (lo <= hi)    {
        int mid = lo + (hi-lo)/2;
        if (ok(mid) == true)    {
            ans = max(ans, mid);
            lo = mid+1;
        } else  {
            hi = mid - 1;
        }
    }
    if (ans == top) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}