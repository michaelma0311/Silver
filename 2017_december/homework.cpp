#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> lis;

int main()  {
    freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);

    cin >> n;
    lis.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> lis[i];
    }
    long long cursu = lis.back();
    long long mi = lis.back();
    vector<long double> ans;
    ans.resize(n);
    long double ma;
    for (long long i = n-2; i >= 0; i--)  {
        long long cur = lis[i];
        cursu += cur;
        mi = min(mi, cur);
        ans[i] = ((long double) cursu-mi)/((long double) n-i-1);
        ma = max(ans[i], ma);
    }
    //cout << "ADAD" << ma << endl;
    for (long long i = 1; i < n-1; i++) {
        if (ans[i] == ma)   {
            cout << i << endl;
        }
    }
}