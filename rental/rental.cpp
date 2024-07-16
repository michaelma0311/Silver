#include <bits/stdc++.h>

using namespace std;

bool cmp (const pair<int, int>& x, const pair<int, int>& y) {
	return x.first > y.first;
}
int main()  {   
    freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cows[i] = p;
    }
    vector<pair<int, int>> store(m);
    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        store[i].first = k;
        store[i].second = j;
    }
    vector<int> rent(r);
    for (int i = 0; i < r; i++) {
        int j;
        cin >> j;
        rent[i] = j;
        }
    sort(cows.begin(), cows.end(), greater<int>());
    sort(rent.begin(), rent.end(), greater<int>());
    sort(store.begin(), store.end(), cmp);
   vector<int> allrent(n);
    int cur = 0;
    int left = store[0].second;
    for (int i = 0; i < n; i++) {
        //cout << cows[i] << endl;
        int money = 0;
        if (cur >= m)   {
            break;
        }
        int cow = cows[i];
        //cout << cow << endl;
        while (cow != 0)    {
            if (cow > left) {           
                cow -= left;
                money += left*store[cur].first;
                cur += 1;
                if (cur == m)   {
                    break;
                }
                left = store[cur].second;
            }   else    {
                    money += cow*store[cur].first;
                    //cout << cow << endl;
                    left -= cow;
                    cow = 0;
            }
        }
        allrent[i] = money;
    }
    reverse(allrent.begin(), allrent.end());

    long long ans = 0;
    long long a, b;
    for (int i = 0; i < n; i++) {
        if (i >= m) {
            ans += allrent[i];
        }   else    {
            a = allrent[i];
            b = rent[i];
            ans += max(a, b);
        }
    }
    cout << ans << endl;
}