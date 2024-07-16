

/*
ID: michael504
PROG: castle
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<vector<int>> lis;
/*1: wall to the west
2: wall to the north
4: wall to the east
8: wall to the south*/
int num;
int rooms;
int ans;
vector<int> temp;

void dfs(int x, int y, int prevx, int prevy, int count)    {
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true)    {
        return;
    }
    visited[x][y] = true;
    rooms += 1;
    lis[x][y] = count;
    if (grid[x][y]/8 < 1 && x+1 != prevx)   {
        dfs(x+1, y, x, y, count);
    } else  {
        if (x+1 != prevx)   {
            grid[x][y] -= 8;
        }
    }
    if (grid[x][y]/4 < 1 && y+1 != prevy)   {
        dfs(x, y+1, x, y, count);
    } else  {
        if (y+1 != prevy)   {
            grid[x][y] -= 4;
        }
    }
    if (grid[x][y]/2 < 1 && x-1 != prevx)   {
        dfs(x-1, y, x, y, count);
    } else  {
        if (x-1 != prevx)   {
            grid[x][y] -= 2;
        }
    }
    if (grid[x][y]/1 < 1 && y-1 != prevy)   {
        dfs(x, y-1, x, y, count);
    } if (y-1 != prevy) {
        grid[x][y] -= 1;
    }
}

int main()  {
    freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)  {
        vector<int> temp;
        temp.resize(n);
        grid.push_back(temp);
        visited.push_back(temp);
        lis.push_back(temp);

    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //cout << i << ' ' << j << endl;
            cin >> grid[i][j];
        }
    }
    vector<int> temp;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rooms = 0;
            if (visited[i][j] == false) {
                dfs(i, j, -2, -2, cnt);
                num = max(num, rooms);
                cnt += 1;
                temp.push_back(rooms);
            }
        }
    }
    int ma = 0;
    char dir = 'a';
    int curx = 0;
    int cury = 0;
    for (int i = 0; i < m; i++) {
        for (int j = n-1; j >= 0; j--)  {
            if (i >= 1) {
                if (lis[i][j] != lis[i-1][j])   {
                    if ((temp[lis[i][j]] + temp[lis[i-1][j]]) > ma )    {
                        ma = temp[lis[i][j]] + temp[lis[i-1][j]];
                        curx = i;
                        cury = j;
                        dir = 'N';
                    } else if ((temp[lis[i][j]] + temp[lis[i-1][j]]) == ma )    {
                        if (j <= cury)   {
                            ma = temp[lis[i][j]] + temp[lis[i-1][j]];
                            curx = i;
                            cury = j;
                            dir = 'N';
                        }
                    }
                }
            }
            if (j < n-1)   {
                if (lis[i][j] != lis[i][j+1])   {
                    if (temp[lis[i][j]] + temp[lis[i][j+1]] > ma)    {
                        dir = 'E';
                        curx = i;
                        cury = j;
                        ma = temp[lis[i][j]] + temp[lis[i][j+1]];
                    } else if (temp[lis[i][j]] + temp[lis[i][j+1]] == ma)    {
                        if (j <= cury)   {
                            if (curx != i || cury != j) {
                                dir = 'E';
                                curx = i;
                                cury = j;
                            }
                            
                        }
                    }
                }
            }
        }
        
    }
    cout << cnt << endl;
    cout << num << endl;
    cout << ma << endl;
    cout << curx+1 << ' ' << cury+1 << ' ' << dir << endl;
}