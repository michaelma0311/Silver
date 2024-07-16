/*
ID: michael504
LANG: C++
TASK: hamming
*/
#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
    bitset<8> c(a^b);
    return c.count();
}

int main()  {
    freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);

    int n, b, d;
    cin >> n >> b >> d;
    vector<int> ans;
    for (int i = 0; i < (1<<b); i++)    {
        bool ok = true;
        for (int j : ans)   {
            if (solve(i, j) < d)    {
                ok = false;
                break;
            }
        }
        if (ok == true) {
            ans.push_back(i);
            if (ans.size() == n)    {
                break;
            } 
        }
    }
    for (int i = 0; i < n-1; i++) {
        if ((i+1)% 10 == 0) {
            cout << ans[i] << endl;
        } else  {
            cout << ans[i] << ' ';
        }
    }
    cout << ans[n-1] << endl;
}   