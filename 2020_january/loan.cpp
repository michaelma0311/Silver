#include <bits/stdc++.h>

using namespace std;
long long n, k, m;
bool valid(long long x, long long left, long long count)   {
    long long y = left/x;
    //cout << "Adad" << ' ' << x << ' ' << y << ' ' << left << endl;
    if (y <= m) {
        return m*count >= left;
    }
    if (count <= 0 || left <= 0)    {
        return left <= 0;
    }
    long long give = min(((left - x*y)/y) + 1, count);
    return valid(x, left-give*y, count-give);
}

int main()  {
    freopen("loan.in","r",stdin);
	freopen("loan.out","w",stdout);
    cin >> n >> k >> m;
    long long l = 1;
    long long r = 1e12;
    while(l < r) {
        long long mid = (l + r + 1) / 2;
        if(valid(mid, n, k)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}