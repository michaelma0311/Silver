#include <bits/stdc++.h>

using namespace std;


int main()  {
    freopen("paintbarn.in","r",stdin);
	freopen("paintbarn.out","w",stdout);
    int n, k;
    cin >> n >> k;
    int barn[1001][1001];
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1] += 1;
        barn[x2][y2] += 1;
        barn[x1][y2] -= 1;
        barn[x2][y1] -= 1;

    } 
    int ans = 0;
    for (int i = 0; i < 1001; i++)   {
        for (int j = 0; j < 1001; j++)  {
            if (i != 0) {
                barn[i][j] += barn[i-1][j];
            }
            if ( j != 0)    {
                barn[i][j] += barn[i][j-1];
            }
            if (i != 0 && j != 0)   {
                barn[i][j] -= barn[i-1][j-1];
            }
            if (barn[i][j] == k)    {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}