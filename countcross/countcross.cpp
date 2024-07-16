#include <bits/stdc++.h>

using namespace std;

pair<int, int> grass[105];
int ans, n, k, r;
int r1, c1, r2, c2;
const int p = 102;
int visited[p][p];
int grid[p][p];
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

void ff(int r, int c, int cur, int p)  {
    visited[r][c] = cur;
    for (int i = 0; i < 4; i++) {
        int tempr = r+dirx[i];
        int tempc = c+diry[i];
        if (!visited[tempr][tempc] && (grid[r][c] & (1 << i)) == 0)  {
            ff(tempr, tempc, cur, 0);
        }
    }
    
}

int main()  {
    freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;

    for (int i = 0; i < r; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == r2)   {
            if (c1 < c2)    {
                grid[r1][c1] += 2;
                grid[r2][c2] += 8;
            } else  {
                grid[r1][c1] += 8;
                grid[r2][c2] += 2;
            }
        } else  {
            if (r1 < r2)    {
                grid[r1][c1] += 4;
                grid[r2][c2] += 1;
            } else  {
                grid[r1][c1] += 1;
                grid[r2][c2] += 4;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)    {
            visited[i][n+1] = 1;
            visited[i][0] = 1;
            visited[n+1][i] = 1;
            visited[0][i] = 1;
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> grass[i].first >> grass[i].second;

    }
    int ans = 0;
    int cur;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)    {
            if (visited[i][j] == false) {
                cur += 1;
                ff(i, j, cur, 0);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            if (visited[grass[i].first][grass[i].second] != visited[grass[j].first][grass[j].second])   {
                 ans += 1;
            }
        }
    }
    cout << ans << endl;
}