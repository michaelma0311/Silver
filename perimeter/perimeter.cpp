#include <bits/stdc++.h>

using namespace std;
const int r = 1010;
char grid[r][r];
bool visited[r][r];
long long tempp = 0;
long long tempa = 0;
long long realp = 0;
long long reala = 0;
int n;
void ff(int x, int y)   {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        tempp += 1;
        return;
    }
    
    
    if (visited[x][y] == true)  {
        return;
    }
    if (grid[x][y] == '.')  {
        tempp += 1;
        return;
    }
    visited[x][y] = true;
    if (grid[x][y] == '#')  {
        tempa += 1;
    }
    ff(x+1, y);
    ff(x-1, y);
    ff(x, y-1);
    ff(x, y+1);
}
int main()  {
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && grid[i][j] == '#') {
                ff(i, j);
            }
            if (reala == tempa)  {
                int q = min(realp, tempp);
                realp = q;
            } else if (tempa > reala)  {
                reala = tempa;
                realp = tempp;
            }
            tempa = 0;
            tempp = 0;
        }
    }
    cout << reala << ' ' << realp << endl;
}