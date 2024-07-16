/*
ID: michael504
LANG: C++
TASK: game1
*/
#include <bits/stdc++.h>

using namespace std;
int n;
int sum[101];
int best[101][101];

int main()
{
    freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> best[i][i];
        sum[i] = sum[i-1] + best[i][i];
        //cout << "sum " << sum[i] << ' ' ;
    }
    //cout << endl;
   
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j+i <= n; j++)   {
            best[j+i][j] = sum[j+i]-sum[j-1] - min(best[j+i-1][j], best[j+i][j+1]);
            //cout << i << ' ' << j << ' ' << best[j+i][j] << ' ' << sum[j+i] << ' ' << sum[j-1] << ' ' << best[j+i-1][j] << ' ' << best[j+i][j+1] << endl;
        }
    }
    cout << best[n][1] << " " << sum[n] - best[n][1] << endl;
}