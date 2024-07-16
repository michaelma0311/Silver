#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("cycle.in","r",stdin);
    long long n, k;
    cin >> n >> k;
    vector<long long> a(k);
    vector<long long> b(k);
    vector<pair<long long, long long>> lis(n);
    fill(lis.begin(), lis.end(), make_pair(-1, -1));
    for (long long i = 0; i < k; i++) {
        cin >> a[i];
        a[i] -= 1;
        lis[a[i]].first = i;
    }
    for (long long i = 0; i < k; i++) {
        cin >> b[i];
        b[i] -= 1;
        lis[b[i]].second = i;
    }
    map<long long, long long> ans;
    long long sol = 0;
    map<long long, long long> ans2;
    for (long long i = 0; i < n; i++) {
       // cout << lis[i].first << ' ' << lis[i].second << endl;
        if (lis[i].first == -1 || lis[i].second == -1)  {
            if (lis[i].first == -1 && lis[i].second == -1)  {
                sol += 1;
            }
            continue;
        }
        //cout << "ADADAD" << endl;
        //long long x = lis[i].first - lis[i].second;
        long long y = abs(lis[i].first - lis[i].second);
        long long z = k-abs(lis[i].first - lis[i].second);
        //if (ans.count(x) == 0)  {
        //    ans[x] = 1;
        //} else  {
        //    ans[x] += 1;
        //}
       //if (y != x) {
        if (ans.count(y) == 0)  {
            ans[y] = 1;
        } else  {
            ans[y] += 1;
        }
        //}
        if (z != y)   {
            if (ans.count(z) == 0)  {
                ans[z] = 1;
            } else  {
                ans[z] += 1;
            }
        }
        long long x = lis[i].first + lis[i].second;
        if (ans2.count(x) == 0) {
            ans2[x] = 1;
        } else  {
            ans2[x] += 1;
        }
        if (x+k != x)   {
            if (ans2.count(x+k) == 0)   {
                ans2[x+k] = 1;
            } else  {
                ans2[x+k] += 1;
            }
        }
    }
    long long temp = 0;
    for (const auto& pair : ans) {
        //cout << "inside " << pair.first << ' ' << pair.second << endl;
        temp = max(temp, pair.second);
    }
    for (const auto& pair : ans2) {
        //cout << "inside " << pair.first << ' ' << pair.second << endl;
        temp = max(temp, pair.second);
    }
    //cout << sol << ' ' << temp << endl;
    cout << sol + temp << endl;

}