#include <bits/stdc++.h>

using namespace std;
long long n, k, m;
bool check(long long x, long long left, long long count)   {
    
}

int main()  {
    freopen(" .in","r",stdin);
	freopen("loan.out","w",stdout);
    cin >> n >> k >> m;
    long long l = 1;
    long long r = 1e12;
    long long ans;

    while (l < r)   {
        long long mid = (l+r)/2;
        if (check(mid, n, 0)) {
            ans = mid;
            l = mid+1;
        } else  {
            r = mid-1;
        }
    }
}