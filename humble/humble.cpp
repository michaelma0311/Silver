/*
ID: michael504
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
    int k, n;
    cin >> k >> n;
    vector<int> lis(k);
    for (int i = 0; i < k; i++) {
        cin >> lis[i];
    }
    long long h[100005], last[100005];
    h[0] = 1;
    for (int i = 1; i <= n; i++)    {
        h[i] = 1e18;
        for (int j = 0; j < k; j++) {
            while (last[j] < i && lis[j] * h[last[j]] <= h[i-1])    {
                last[j] += 1;
            }
            if (lis[j] * h[last[j]] > h[i-1]) {
                h[i] = min(h[i], lis[j]*h[last[j]]);
            }
        }
    }
    cout << h[n] << endl;
}