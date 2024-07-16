#include <bits/stdc++.h>

using namespace std;

int main()  {
    string a;
    cin >> a;
    int s = a.length();
    vector<long long> dp(6);
    long long ans = 0;
    long long sol = 0;
    for (int i = 0; i < s; i++) {
        dp[0] += 1;
        if (a[i] == 'b')    {
            dp[1] += dp[0];
            dp[0] = 0;
        } else if (a[i] == 'e') {
            dp[2] += dp[1];
            ans += dp[5];
            dp[0] += dp[5];
            dp[1] = 0;
            dp[5] = 0;
        } else if (a[i] == 's') {
            dp[4] += dp[3];
            dp[3] = dp[2];
            
            dp[2] = 0;
        } else if (a[i] == 'i') {
            dp[5] += dp[4];
            dp[4] = 0;
        }
        //cout << dp[0] << ' ' << dp[1] << ' ' << dp[2] << ' ' << dp[3] << ' ' << dp[4] << ' ' << dp[5] << endl;
        //cout << "ans" << ' ' << ans << ' '<< sol << endl;
        sol += ans; 
    }
    cout << sol << endl;
}