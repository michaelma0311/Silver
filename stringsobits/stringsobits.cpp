/*
ID: michael504
LANG: C++
TASK: kimbits
*/
#include <bits/stdc++.h>

using namespace std;
double lis[33][33];

void solve()    {
	for (int i = 0; i < 32; i++)    {
        lis[0][i] = 1;
    }
	for(int i=1; i<=32; i++)    {
        for(int j=0; j<=32; j++)    {
            if(j == 0)  {
                lis[i][j] = 1;
            } else  {
                lis[i][j] = lis[i-1][j-1] + lis[i-1][j];
            }
        }
    }
}

void rec(int n, int l, double k)    {
    if (n == 0) {
        return;
    }

    double cur = lis[n-1][l];
    //cout << "ADADA " << n << ' ' << l << ' ' << k << ' ' << cur << endl;
    if (cur <= k)   {
        cout << "1";
        rec(n-1, l-1, k-cur);
    } else  {
        cout << "0";
        rec(n-1, l, k);
    }
}

int main()  {
    freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
    int n, l;
    double k;
    cin >> n >> l;
    cin >> k;
    solve();
    rec(n, l, k-1);
    cout << endl;
}