#include <bits/stdc++.h>
using namespace std;
int n, m;
const int r = 505;
int grid[r][r];
bool visited[r][r];
int way[r][r];
int num = 0;
void dfs(int x, int y, int mid) {
    if (visited[x][y] == true)  {
        return;
    }
    visited[x][y] = true;
    if (way[x][y] == 1) {
        num += 1;
    }
    if (x+1 < n && abs(grid[x+1][y] - grid[x][y]) <= mid)  {
        dfs(x+1, y, mid);
    }
    if (x-1 >= 0 && abs(grid[x-1][y] - grid[x][y]) <= mid)  {
        dfs(x-1, y, mid);
    }
    if (y+1 < m && abs(grid[x][y+1] - grid[x][y]) <= mid)   {
        dfs(x, y+1, mid);
    }
    if (y-1 >= 0 && abs(grid[x][y-1] - grid[x][y]) <= mid)  {
        dfs(x, y-1, mid);
    }

}
int main()  {
    freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    int ma = 0;
    int mi = INT_MAX;
    int x, y;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            ma = max(grid[i][j], ma);
            mi = min(grid[i][j], mi);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> way[i][j];
            if (way[i][j] == 1) {
                x = i;
                y = j;
                count += 1;
            }
        }
    }
    int ans = INT_MAX;
    int lo = 0;
    int hi = ma-mi;
    bool p[r][r];
    while (lo <= hi)    {
        int mid = lo + (hi-lo)/2;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) {
                visited[i][j] = false;
            }
        }
        num = 0;
        dfs(x, y, mid);
        if (num == count)   {
            ans = min(ans, mid);
            hi = mid-1;
        } else  {
            lo = mid+1;
        }
    }
    cout << ans << endl;
}