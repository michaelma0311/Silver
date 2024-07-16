/*
ID: michael504
LANG: C++
TASK: money
*/
#include <bits/stdc++.h>

using namespace std;
int main()  {

	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
    int v, n, a[26];
    long long dp[100001];
    cin >> v >> n;
    for (int i = 0; i < v; i++) {
        cin >> a[i];
    }

	dp[0] = 1;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j <= n; j++)    {
            if (a[i] + j <= n)  {
                dp[a[i] + j] += dp[j];
            }
        }
    }
    cout << dp[n] << endl;
}