#include <bits/stdc++.h>

using namespace std;
int main()  {
    freopen("helpcross.in","r",stdin);
	freopen("helpcross.out","w",stdout);
    long long n, m;
    cin >> n >> m;
    vector<long long> chicken(n);
    vector<pair<long long, long long>> cows(m);
    for (long long i = 0; i < n; i++) {
        cin >> chicken[i];
    }
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        cows[i].first = a;
        cows[i].second = b;
    }
    sort(chicken.begin(), chicken.end());
    sort(cows.rbegin(), cows.rend());
    queue<long long> q;
    long long ans = 0;
    priority_queue<int> lis;
    for (int i : chicken)   {
        while (cows.empty() == false && cows.back().first <= i) {
            lis.push(-cows.back().second);
            cows.pop_back();
        }
        while (lis.empty() == false && -lis.top() < i)  {
            lis.pop();
        }
        if (lis.empty() == false)   {
            lis.pop();
            ans += 1;
        }
    }
    cout << ans << endl;
}