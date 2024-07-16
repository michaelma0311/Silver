#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;
int p = 0;
vector<int> lis;

int solve(int cur)  {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        int k = lis[i]/cur;
        //cout << k << endl;
        for (int j = 0; j < k; j++) {
            temp.push_back(cur);
        }
        if (lis[i] - cur*k != 0)    {
            temp.push_back(lis[i] - cur*k);
        } 
    }
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    int solt = 0;
    for (int i = m/2; i < m && i < temp.size(); i++)  {
        solt += temp[i];
    }
    return solt;
}

int main()  {
    freopen("berries.in","r",stdin);
	freopen("berries.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lis.push_back(x);
    }
    p = *max_element(lis.begin(), lis.end());
    for (int i = 1; i < p; i++) {
        int sol = solve(i);
        //cout << sol << endl;
        ans = max(sol, ans);
    }
    cout << ans << endl;
}