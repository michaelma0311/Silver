#include <bits/stdc++.h>

using namespace std;
const int r = 251;
bool visited[r][r];
int grid[r][r];
int n;
int ff(int x, int y, int size, int c1, int c2)   {
    if (x < 0 || x >= n || y < 0 || y >= n || (grid[x][y] != c1 && grid[x][y] != c2) || visited[x][y] == true) {
        return size;
    }
    visited[x][y] = true;
    size += 1;
    size = ff(x+1, y, size, c1, c2);
    size = ff(x, y+1, size, c1, c2);
    size = ff(x-1, y, size, c1, c2);
    size = ff(x, y-1, size, c1, c2);
    return size;
}
int main()  {
    freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] != true)  {
                ans = max(ans, ff(i, j, 0, grid[i][j], grid[i][j]));
            }
        }
    }
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] != grid[i-1][j]) {
                memset(visited, 0, sizeof(visited));
                //cout << grid[i][j] << ' ' << grid[i-1][j] << ' ' << i << ' ' << j << endl;
                ans = max(ans, ff(i, j, 0, grid[i][j], grid[i-1][j]));
                if (ans >= n*n/2)   {
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] != grid[i][j-1]) {
                memset(visited, 0, sizeof(visited));
                ans = max(ans, ff(i, j, 0, grid[i][j], grid[i][j-1]));
                if (ans >= n*n/2)   {
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
}