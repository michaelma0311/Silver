/*
ID: michael504
LANG: C++
TASK: nocows
*/

#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(n+1);
    for (int i = 0; i < n+1; i++)   {
        dp[i].resize(k+1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++)   {
            if (i == 1) {
                dp[i][j] = 1;
            } else  {
                for (int z = 1; z < i; z++) {
                    //cout << z << ' ' << j << ' ' << i-z-1 << ' ' << dp[z][j-1] << ' ' << dp[i-z-1][j-1] << endl;
                    dp[i][j] += dp[z][j-1] * dp[i-z-1][j-1];
                    dp[i][j] %= 9901;
                }
            }
        }
    }
    //for (int i = 1; i < n+1; i++)   {
        //for (int j = 1; j < k+1; j++)   {
           // cout << dp[i][j] << ' ';
        //}
        //cout << endl;
   // }
    //cout << dp[n][k] << ' ' << dp[n][k-1] << endl;
    cout << (dp[n][k] - dp[n][k-1] + 9901)%9901 << endl;
}