#include <bits/stdc++.h>

using namespace std;
int n, k, l;
vector<int> lis;
bool yes(int h) {
    if (lis[n-h] < h-k) {
        return false;
    }
    long long cur = 0;
    for (int i = n-1; i >= n-h; i--)  {
        if (lis[i] <= h)    {
            cur += h-lis[i];
        } 
    }
    if (cur <= (long long)  k*l)   {
        return true;
    }
    return false;
}
int main()  {
    cin >> n >> k >> l;
    lis.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
    }
    sort(lis.begin(), lis.end());
    int lo = 0;
    int hi = n+1;
    while (lo < hi-1)   {
        int mid = (lo+hi)/2;
        //cout << mid << endl;
        //cout << yes(3) << endl;
        if (yes(mid))   {
            lo = mid;
        } else  {
            hi = mid;
        }
    }
    cout << lo << endl;
}