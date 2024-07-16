#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> boots;
bool visited[250][250];
vector<pair<int, int>> shoes;
int ans = INT_MAX;
void dfs(int de, int disc)  {
    if (visited[de][disc] == true)  {
        return;
    }
    visited[de][disc] = true;
    if (de >= n-1)  {
        ans = min(ans, disc);
        return;
    }
    int temp = de+1;
    while (temp <= de+shoes[disc].second && temp < n)   {
        if (boots[temp] <= shoes[disc].first)   {
            dfs(temp, disc);
        }
        temp += 1;
    }
    for (int i = disc; i < m; i++)  {
        if (boots[de] <= shoes[i].first)    {
            dfs(de, i);
        }
    }
}

int main()  {
    freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        boots.push_back(k);
    }
    //cout << "adadada" << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        shoes.push_back(make_pair(x, y));
    }
    dfs(0, 0);
    cout << ans << endl;
}