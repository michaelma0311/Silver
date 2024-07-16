#include <bits/stdc++.h>

using namespace std;

void solve()    {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> lis(m);
    vector<int> arr(m+1);
    bool result = true;
    int oddmax, oddmin, evenmax, evenmin;
    int sol = 0;
    vector<int> ans(m);
    vector<bool> tempero(m); 
    int tempind = m-1;
    arr[m] = 0;
    for (int i = 0; i < m; i++) {
        oddmax = -1;
        oddmin = INT_MAX;
        evenmax = -1;
        evenmin = INT_MAX;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (x % 2 == 1) {
                oddmin = min(oddmin, x);
                oddmax = max(oddmax, x);
            } else  {
                evenmin = min(evenmin, x);
                evenmax = max(evenmax, x);
            }
        }
        if (oddmax == -1)  { 
            sol += -1*evenmin;
            lis[i] = make_pair(-1*evenmin, evenmax);
            tempero[i] = true;
        } else if (evenmax == -1)  { 
            tempero[i] = false;
            sol += -1*oddmin;
            lis[i] = make_pair(-1*oddmin, oddmax);
        } else if (evenmax > oddmax)  {
            tempero[i] = true;
            lis[i] = make_pair(oddmax, evenmax);
            sol += oddmax;
        } else  {
            tempero[i] = false;
            lis[i] = make_pair(evenmax, oddmax);
            sol += evenmax;
        }
        //true false even odd
        if (sol >= n)   {
            result = false;
        }
        ans[i] = sol;
        //ans
    }
    if (result == false || sol >= n)   {
        cout << -1 << endl;
        return;
    }
    int sufftemp = 0;
    for (int i = m-1; i > 0; i--)   {
        sufftemp = max(0, sufftemp + lis[i].first);
        arr[i] = sufftemp;
    }
    int differe = 0;
    for (int i = 0; i < m; i++) {
        if (tempero[i] == true)   {
            continue;
        }
        pair<int, int> cur = lis[i];
        int even = cur.second;
        int odd = cur.first;
        int tempval = ans[i] + differe + arr[i+1];
        if (tempval + even-odd < n) {
            differe += (even-odd);
            tempero[i] = true;
        }
    }
    for (int i = 0; i < m-1; i++) {
        if (tempero[i] == true)   {
            cout << "Even" << ' ';
        } else  {
            cout << "Odd" << ' ';
        }
    }
    //print last value
    if (tempero.back() == true)  {
        cout << "Even" << endl;
    } else  {
        cout << "Odd" << endl;
    }
}

signed main()  {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
    }
}