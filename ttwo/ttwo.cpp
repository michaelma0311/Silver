#include <bits/stdc++.h>

using namespace std;

const int n = 10;
string grid[n];
pair<int, int> cow, farmer;
int x[] = {0, 1, -1, 0};
int y[] = {-1, 0, 0, 1};

bool valid(pair<int, int> z)    {
    if (z.first < 0 || z.first >= 10)   {
        return false;
    }
    if (z.second < 0 || z.second >= 10) {
        return false;
    }
    if (grid[z.first][z.second])    {
        return false;
    }
    return true;
}

struct state    {
    pair<int, int> fp, cp;  int fd, cd;
};
bool visited[10][10][10][10][4][4];
int main()  {
    for (int i = 0; i < 10; i++) {
        cin >> grid[i];
        for (int j = 0; j < 10; j++)  {
            if (grid[i][j] == 'F')   {
                farmer = make_pair(i, j);
            }
            if (grid[i][j] == 'C') {
                cow = make_pair(i, j);
            }
        }
    }
    cout << farmer.first << ' ' << farmer.second << ' ' << cow.first << ' '<< cow.second << endl;
    state cur = {farmer, cow, 0, 0};
    int ans = 0;
    while (cur.fp != cur.cp)    {
        if (visited[cur.fp.first][cur.fp.second][cur.cp.first][cur.cp.second][cur.fd][cur.cd] == true)  {
            break;
        }
        visited[cur.fp.first][cur.fp.second][cur.cp.first][cur.cp.second][cur.fd][cur.cd] = true;
        pair<int, int> temp = {cur.fp.first+x[cur.fd], cur.fp.second+y[cur.fd]};
        if (valid(temp) == false)   {
            cur.fd = (cur.fd+1)%4;
        } else  {
            cur.fp = temp;
        }
        pair<int, int> temp2 = {cur.cp.first+x[cur.cd], cur.cp.second+y[cur.cd]};
        if (valid(temp2) == false)  {
            cur.cd = (cur.cd+1)%4;
        } else  {
            cur.cp = temp2;
        }
        ans += 1;
    }
    cout << ans << endl;
    if (cur.fp != cur.cp)   {
        cout << 0 << endl;
    } else  {
        cout << ans << endl;
    }

    
}