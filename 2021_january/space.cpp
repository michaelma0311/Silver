#include <bits/stdc++.h>

using namespace std;

int main()  {
    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int vert = 0;
    
    for (int i = 0; i < n; i++) {
        int od = 0;
        int ev = 0;
        for (int j = 0; j < n; j++) {
            if (j%2 == 0)   {
                ev += grid[i][j];
            } else  {
                od += grid[i][j];
            }
        }
        vert += max(ev, od);
    }
    int hori = 0;
    for (int i = 0; i < n; i++) {
        int od = 0;
        int ev = 0;
        for (int j = 0; j < n; j++) {
            if (j%2 == 0)   {
                ev += grid[j][i];
            } else  {
                od += grid[j][i];
            }
        }
        hori += max(ev, od);
    }
    cout << max(hori, vert) << endl;
}