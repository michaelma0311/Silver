/*
ID: michael504
LANG: C++
TASK: inflate
*/
#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
    int tot, n;
    cin >> tot >> n;
    vector<pair<int, int>> lis(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lis[i] = make_pair(y, x);
    }
    vector<pair<int, int>> dp(tot+1);
    int ans = 0;
    //first one is points second one is minutes
    for (int i = 0; i < n; i++)   {
        for (int j = 0; j < tot+1; j++) {
            
            if (lis[i].first + j > tot || dp[j].second + lis[i].first > tot) {
                continue;
            } 
            //cout << j << ' ' << lis[i].first << ' ' << lis[i].second << ' ' << dp[j].first << ' ' << dp[j+lis[i].first].first << endl;
            //cout << j << ' ' << lis[i].first << ' ' << dp[j+lis[i].first].first << ' ' << dp[j+lis[i].first].second
            if (dp[j].first + lis[i].second > dp[j+lis[i].first].first) {
                dp[j+lis[i].first].first = dp[j].first + lis[i].second;
                dp[j+lis[i].first].second = lis[i].first + dp[j].second; 
            } else if (dp[j].first + lis[i].second == dp[j+lis[i].first].first)    {
                dp[j+lis[i].first].second = min(dp[j+lis[i].first].second, lis[i].first + dp[j].second); 
            }
            //dp[j+lis[i].first].first += max(dp[j+lis[i].first].first, dp[j].first + lis[i].second);
            //[j+lis[i].first].second += (lis[i].first+dp[j].second);
            ans = max(ans, dp[j+lis[i].first].first);
        }
    }
    //for (int i = 0; i < tot+1; i++) {
        //cout << dp[i].first << " ada " << dp[i].second << ' ';
    //}
    //cout << endl;
    cout << ans << endl;
}