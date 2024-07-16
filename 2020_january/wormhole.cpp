#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MX = 1e5;
vector<pair<int, int>> pairs[MX];
vector<int> lis(MX), comp(MX);

void dfs(int cur, int c, int temp)    {
    comp[cur] = c;
    for (auto i : pairs[cur])   {
        if (i.second < temp || comp[i.first] != -1)    {
            continue;
        }
        dfs(i.first, c, temp);
    }
}

bool ok(int cur)    {
    fill(comp.begin(), comp.end(), -1);
    int c = -1;
    for (int i = 0; i < n; i++) {
        if (comp[i] != -1) {
            continue;
        }
        c += 1;
        dfs(i, c, cur);
    }
    for (int i = 0; i < n; i++) {
        //cout << comp[i] << ' ' << comp[lis[i]] << endl;
        if (comp[i] != comp[lis[i]])    {
            return false; 
        }
    }
    return true;
}

int main()  {
    freopen("wormsort.in","r",stdin);
	freopen("wormsort.out","w",stdout);
    cin >> n >> m;
    int hi = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x -= 1;
        lis[i] = x;
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        pairs[x].push_back(make_pair(y, z));
        pairs[y].push_back(make_pair(x, z));
        hi = max(hi, z);
    }
    int lo = 1;
    int ans = 0;
    int k = hi;
    while (lo <= hi)    {
        int mid = lo + (hi-lo)/2;
        //cout << mid << endl;
        if (ok(mid) == true)    {
            ans = max(ans, mid);
            lo = mid+1;
        } else  {
            hi = mid - 1;
        }
    }
    if (ans == k)   {
        cout << -1 << endl;
    } else  {
        cout << ans << endl;
    }
}