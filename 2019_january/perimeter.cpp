#include <bits/stdc++.h>

using namespace std;

long long n;
vector<vector<char>> grid;
vector<vector<bool>> visited;
long long tempa, tempp, reala, realp;

void ff(long long x, long long y)   {
    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == '.')   {
        tempp += 1;
        return;
    }
    if (visited[x][y])  {
        return;
    }
    visited[x][y] = true;
    tempa += 1;
    ff(x+1, y);
    ff(x-1, y);
    ff(x, y+1);
    ff(x, y-1);
}

int main()  {
    freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
    cin >> n;
    grid.resize(n);
    visited.resize(n);
    for (long long i = 0; i < n; i++) {
        grid[i].resize(n);
        visited[i].resize(n);
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    tempa = 0;
    tempp = 0;
    reala = 0;
    realp = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (visited[i][j] == false && grid[i][j] == '#') {
                ff(i, j);
                if (tempa > reala)  {
                    reala = tempa;
                    realp = tempp;
                } else if (tempa == reala) {
                    realp = min(tempp, realp);
                }
                tempp = 0;
                tempa = 0;
            }
        }
    }
    cout << reala << ' ' << realp << endl;
}