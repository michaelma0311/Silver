#include <bits/stdc++.h>

using namespace std;

const int r = 100000;
pair<int, int> pairs[r];

int main()  {
    freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    sort(pairs, pairs+m);
    int lo = 0;
    int hi = pairs[m-1].second - pairs[0].first + 1;
    int most = pairs[m-1].second;
    while (lo < hi) {
        int mid = lo + (hi+1-lo) / 2;
        int count = 1;
        int curinv = 0;
        int temp = 0;
        //cout << lo << ' ' << hi << ' ' << mid << endl;
        int cur = pairs[0].first;
        while (cur+mid < most)  {
            while (cur+mid > pairs[curinv].second)  {
                curinv += 1;
            }
            temp = pairs[curinv].first;
            cur = max(temp, cur+mid);
            count += 1;
            if (count == n) {
                break;
            }
        }
        //cout << count << endl;
        if (count == n) {
            lo = mid;
        } else  {
            hi = mid-1;
        }
    }
    
    cout << lo << endl;
}