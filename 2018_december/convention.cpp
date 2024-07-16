#include <bits/stdc++.h>

using namespace std;

long long n, m, c;
vector<long long> lis;

bool solve(long long cur) {
    long long cnt = 1;
    long long start = lis[0];
    long long tempcnt = 0;
    for (long long i = 1; i < n; i++) {
        //cout << cur << ' ' << lis[i] << ' ' << start << ' ' << tempcnt << ' ' << cnt << endl;
        if (lis[i] - start > cur || i-tempcnt+1 > c)   {
            cnt += 1;
            tempcnt = i;
            start = lis[i];
        } 
    }

    //cout << cnt << ' ' << cur << endl;
    return cnt <= m;
}

int main()  {
    freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
    cin >> n >> m >> c;
    lis.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> lis[i];
        //cout << lis[i] << endl;
    }
    sort(lis.begin(), lis.end());
    long long l = 0;
    long long h = 1e9+1;
    long long ans = 0;
    long long mid;
    //cout << solve(99220) << endl;
    while (l <= h)  {
        mid = (l+h)/2;
        if (solve(mid)) {
            h = mid-1;
            ans = mid;
        } else  {
            l = mid+1;
        }
    }
    cout << ans << endl;
    //cout << solve(103325) << endl;

}