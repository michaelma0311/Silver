#include <bits/stdc++.h>

using namespace std;

long long n, m;


vector<pair<long long, long long>> lis;

bool check(long long d) {
    //cout << "START " << d << endl;
    long long cur = -1e18;
    cur -= 2;
    long long cnt = 0;
    for (long long i = 0; i < m; i++) {
        long long x = lis[i].first;
        long long y = lis[i].second;
        if (x-cur >= d) {
            cur = x;
            cnt += 1;
        }
        if (cnt == n)   {
            //cout << d << ' ' << n;
            return true;
        }
        //cout << cur << ' ' << x << ' ' << y << ' ' << d<< endl;
        //cout << cur << ' ' << cnt << endl;
        while (cur + d <= y)    {
            cur += d;
            //cout << cur << ' ' << d << ' ' << cnt << endl;

            cnt += 1;
            //cout << cur << ' ' << cnt << ' ' << n << endl;
            if (cnt == n)   {
                //cout << d << ' ' << n << endl;
                return true;
            }
        }
    }
    return false;
}

int main()  {
    freopen("socdist.in","r",stdin);
	freopen("socdist.out","w",stdout);
    cin >> n >> m;  
    lis.resize(m);
    for (long long i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        lis[i] = make_pair(x, y);
    }
    sort(lis.begin(), lis.end());
    long long l = 1;
    long long r = lis.back().second;
    long long mid;
    long long ans = 1;
    while (l <= r)   {
        mid = (l+r)/2;
        if (check(mid)) {
            //cout << mid << endl;
            ans = max(ans, mid);
            l = mid+1;
        } else  {
            r = mid-1;
        }
    }
    cout << ans << endl;
}