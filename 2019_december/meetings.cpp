#include <bits/stdc++.h>

using namespace std;

int main()  {
    int n, l;
    vector<pair<int, pair<int, int>>> lis;
    vector<int> left;
    vector<int> right;
    vector<pair<int, int>> timesw;
    vector<int> lx;
    int total = 0;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int w, x, d;
        cin >> w >> x >> d;
        lis.push_back(make_pair(x, make_pair(w, d)));
        total += w;
        if (d == -1)    {
            lx.push_back(x);
        }
    }
    //cout << total << endl;
    sort(lis.begin(), lis.end());
    for (int i = 0; i < n; i++) {
        if (lis[i].second.second == -1)    {
            left.push_back(lis[i].first);
        } else  {
            right.push_back(l-lis[i].first);
        }
    }
    for (int i = 0; i < left.size(); i++)    {
        timesw.push_back(make_pair(left[i], lis[i].second.first));
        cout << lis[i].second.first << endl;
    }
    
    reverse(right.begin(), right.end());
    //cout << right[0].first << endl;
    for (int i = 0; i < right.size(); i++)  {
        timesw.push_back(make_pair(right[i], lis[n-i-1].second.first));
    }
    sort(timesw.begin(), timesw.end());

    int temp = 0;
    int cur = 0;
    while (temp * 2 < total)    {
        temp += timesw[cur].second;
        cur++;
    }
    //cout << cur << endl;
    cur = timesw[cur-1].first;
    sort(lx.begin(), lx.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i].second.second == -1) {
            ans += upper_bound(lx.begin(), lx.end(), lis[i].first + 2*cur) - lower_bound(lx.begin(), lx.end(), lis[i].first);
        }
    }
    cout << ans << endl;    
}