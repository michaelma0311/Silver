
/*
ID: michael364
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
vector<int> dif;
void floodfill(int x, int y, int prevx, int prevy, int count)    {
    //
    if (x < 0 || x >= m || y < 0 || y >= n) {
        //cout << "waafaf" << endl;
        return;
    } else if  (visited[x][y] == true)  {
        return;
    }
    //cout << "adadadada" << endl;
    //cout << "inside " << x << ' ' << y << ' ' << grid[x][y] << endl;
    rooms += 1;
    lis[x][y] = count;
    visited[x][y] = true;
    if (grid[x][y]/8 < 1 && x+1 != prevx) {
        floodfill(x+1, y, x, y, count);
    } else {
        if (x+1 != prevx)   {
            grid[x][y] -= 8;
        }
        
    }
    if (grid[x][y]/4 < 1 && y+1 != prevy) {
        floodfill(x, y+1, x, y, count);
    } else  {
        if (y+1 != prevy)   {
            grid[x][y] -= 4;
        }
        
    }
    if (grid[x][y]/2 < 1 && x-1 != prevx) {
        floodfill(x-1, y, x, y, count);
    } else  {
        if (x-1 != prevx)   {
            grid[x][y] -= 2;
        }
        
    }
    if (grid[x][y]/1 < 1 && y-1 != prevy) {
        floodfill(x, y-1, x, y, count);
    }else  {
        if (y-1 != prevy)   {
            grid[x][y] -= 1;
        }
        
    }
}

pair<char, pair<int, int>> check(int x, int y)    {
    char side = 'a';
    int big = 0;
    if (x >= 1) {
        if (lis[x][y] != lis[x-1][y])   {
            if (dif[lis[x][y]] + dif[lis[x-1][y]] > big)    {
                side = 'N';
            } else if (dif[lis[x][y]] + dif[lis[x-1][y]] == big)    {
                if (side == 'E')    {
                    side = 'N';
                }
            }
        }
    }
    if (y < m-1)    {
        if (lis[x][y] != lis[x][y+1])   {
            if (dif[lis[x][y]] + dif[lis[x][y+1]] > big)    {
                side = 'N';
            } else if (dif[lis[x][y]] + dif[lis[x-1][y]] == big)    {
                if (side == 'E')    {
                    side = 'N';
                }
            }
        }
    }
    
    return make_pair(side, make_pair(x, y));
}

int main()  {
    freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        temp.resize(n);
        grid.push_back(temp);
        visited.push_back(temp);
        lis.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            //cout << "adad " << grid[i][j] << ' ' << i << ' ' << j << endl;
        }
    }
    rooms = 0;
    int ans = 0;
    num = 0;
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rooms = 0;
            //cout << "adadada" << endl;
            if (visited[i][j] == false) {
                num += 1;
                floodfill(i, j, -10, -10, count);
                count += 1;
                ans = max(ans, rooms);
                dif.push_back(rooms);
            }
            //cout << rooms << endl;
        }
    }
    char side = 'a';
    int curx = 0;
    int cury = 0;
    int big = 0;
    for (int x = 0; x < m ; x++) {
        for (int y = n-1; y >= 0; y--) {
            if (x >= 1) {
                if (lis[x][y] != lis[x-1][y])   {
                    if (dif[lis[x][y]] + dif[lis[x-1][y]] > big)    {
                        side = 'N';
                        curx = x;
                        cury = y;
                        big = dif[lis[x][y]] + dif[lis[x-1][y]];
                } else if (dif[lis[x][y]] + dif[lis[x-1][y]] == big)    {
                    if (y <= cury)  {
                        side = 'N';
                        curx = x;
                        cury = y;
                        big = dif[lis[x][y]] + dif[lis[x-1][y]];

                        }
                    
                    }
                }
            }
    
            if (y < n-1)    {
                //cout << "adadadad" << endl;
                if (lis[x][y] != lis[x][y+1])   {
                    if (dif[lis[x][y]] + dif[lis[x][y+1]] > big)    {
                        side = 'E';
                        curx = x;
                        cury = y;
                        big = dif[lis[x][y]] + dif[lis[x][y+1]];
                    } else if (dif[lis[x][y]] + dif[lis[x][y+1]] == big)    {
                        if (y <= cury)   {
                            if (curx != x || cury != y) {
                                side = 'E';
                                curx = x;
                                cury = y;
                            }
                            
                        }
                    }
                    
                }
            }
        }
    }
    
    cout << num << endl;
    cout << ans << endl;
    cout << big << endl;
    cout << curx+1 << ' ' << cury+1 << ' ' << side << endl;
}
