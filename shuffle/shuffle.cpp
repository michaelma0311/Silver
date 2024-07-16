#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> lis(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		lis[a[i]]++;
	}

	ll ans = n;
	queue<ll> no_cows;

	for (int i = 0; i < n; i++) {
        if (lis[i] == 0)    {
            ans -= 1;
            no_cows.push(i);
        }
    }
    while (no_cows.empty() == false)    {
        ll cur = no_cows.front();
        no_cows.pop();
        lis[a[cur]] -= 1;
        if (lis[a[cur]] == 0)   {
            no_cows.push(a[cur]);
            ans -= 1;
        }
    }
	cout << ans << endl;
}
