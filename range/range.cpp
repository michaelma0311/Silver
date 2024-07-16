/*
ID: michael504
LANG: C++
TASK: range
*/
#include <bits/stdc++.h>

using namespace std;


#define MAXN 250


int goodsq[MAXN][MAXN];
int bigsq[MAXN][MAXN];
int tot[MAXN+1];
int n;

int main()  {
    freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);


    cin >> n;
    for (int i = 0; i < n; i++) {
        string y;
        cin >> y;
        for (int j = 0; j < n; j++) {
            if (y[j] == '0')    {
                goodsq[i][j] = 0;
            } else  {
                goodsq[i][j] = 1;
            }
        }
    }
    //cout << "ADADAD" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int left, right;
            left = -1;
            right = -1;
            for (int k = i; k >= 0; k--)    {
                if (!goodsq[k][j])   {
                    left = k;
                    break;
                }
            }
            for (int k = j; k >= 0; k--)    {
                if (!goodsq[i][k])   {
                    right = k;
                    break;
                }
            }
            int cur = min(i-left, j-right);
            if (i > 0 && j > 0) {
                cur = min(cur, bigsq[i-1][j-1]+1);
            }
            bigsq[i][j] = cur;
            //cout << cur << ' ' << i << ' ' << j << ' ' << left << ' ' << right << ' ' << bigsq[i][j] << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 2; k < bigsq[i][j]+1; k++)   {
                tot[k] += 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)    {
        if (tot[i]) {
            cout << i << ' ' <<  tot[i] << endl;    
        }
    }
    
}