#include <bits/stdc++.h>

using namespace std;


int main()  {
    freopen("paintbarn.in","r",stdin);
	freopen("paintbarn.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid;
    grid.resize(1001);
    for (int i = 0; i < grid.size(); i++)   {
        grid[i].resize(1001);
    }
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        grid[x1][y1] += 1;
        grid[x2][y2] += 1;
        grid[x1][y2] -= 1;
        grid[x2][y1] -= 1;
    }
    int ans = 0;
    for (int i = 0; i < 1001; i++)  {
        for (int j = 0; j < 1001; j++)  {
            if (i > 0)  {
                grid[i][j] += grid[i-1][j];
            }
            if (j > 0)  {
                grid[i][j] += grid[i][j-1];
            }
            if (i > 0 && j > 0) {
                grid[i][j] -= grid[i-1][j-1];
            }
            if (grid[i][j] == k)    {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}