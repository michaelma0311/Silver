#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
bool visited2[250][250];
int c;
int c2;
int n;

void ff(int i, int j, int cur)  {
    if (visited[i][j] != true)  {
        visited[i][j] = true;
        c += 1;
    
        if (i > 0 && grid[i-1][j]==cur)  {
            ff(i-1, j, cur);
        } 
        if (i < n-1 && grid[i+1][j]==cur) {
            ff(i+1, j, cur);
        }
        if (j > 0 && grid[i][j-1]==cur)   {
            ff(i, j-1, cur);
        }
        if (j < n-1 && grid[i][j+1]==cur) {
            ff(i, j+1, cur);
        }
    }
}

void ff2(int i, int j, int cur, int cur2)   {
    
    if (visited2[i][j] == false && (grid[i][j] == cur || grid[i][j] == cur2))   {
        //cout << i << ' ' << j << ' ' << cur << ' ' << cur2 << ' ' << visited2[1][2] << endl;
        visited2[i][j] = true;
        c2 += 1;
        if (i > 0)  {
            ff2(i-1, j, cur, cur2);
        }
        if (i < n-1) {
            ff2(i+1, j, cur, cur2);
        }
        if (j > 0)   {
            ff2(i, j-1, cur, cur2);
        }
        if (j < n-1) {
            ff2(i, j+1, cur, cur2);
        }
    }
}

int main()  {
    freopen("multimoo.in","r",stdin);
	freopen("multimoo.out","w",stdout);
    cin >> n;
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])  {
                continue;
            }
            c = 0;
            ff(i, j, grid[i][j]);
            //cout << "adada " << c << endl;
            ans = max(ans, c);
        }
    }
    //cout << "adada" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (ans2 >= n*n/2)    {
                break;
            }
            if (j > 0 && grid[i][j] != grid[i][j-1])    {
                ff2(i, j, grid[i][j], grid[i][j-1]);
                ans2 = max(ans2, c2);
                c2 = 0;
                memset(visited2, 0, sizeof(visited2));
            }
        }
    }
    cout << ans << endl;
    cout << ans2 << endl;
}   