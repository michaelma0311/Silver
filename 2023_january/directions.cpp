#include<bits/stdc++.h>
using namespace std;

int n;
const int r = 1505;
bool dirs[r][r];
int counts[r][r];
int row[r], col[r];
int ans = 0;

 
void calc(int i, int j, int cur) {
    counts[i][j] += cur;
    
    if (i == n) {
        ans += col[j] * cur;
        return;
    }
    if (j == n) {
        ans += row[i] * cur;
        return;
    }
    
    if (dirs[i][j]) {
        calc(i+1, j, cur);
    } else {
        calc(i, j+1, cur);
    }
}
int main()  {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            dirs[i][j] = (s[j] == 'D');
        }
        int x;
        cin >> x;
        row[i] = x;
    }
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        col[i] = y;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counts[i][j] += 1;
            if (dirs[i][j] == true) {
                counts[i+1][j] += counts[i][j];
            } else  {
                counts[i][j+1] += counts[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans += row[i] * counts[i][n] + col[i] * counts[n][i];
    }
    cout << ans << endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        if (dirs[x][y] == true) {
            dirs[x][y] = false;
            calc(x+1, y, counts[x][y] * -1);
            calc(x, y+1, counts[x][y] );
        } else  {
            dirs[x][y] = true;
            calc(x+1, y, counts[x][y]);
            calc(x, y+1, counts[x][y] * -1);
        }
        cout << ans << endl;
    }
}