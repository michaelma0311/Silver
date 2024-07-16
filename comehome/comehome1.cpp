/*
ID: michael504
LANG: C++
TASK: comehome
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 52;
const int inf = 1e9;

int check(char a)   {
    if (a >= 'a' && a <= 'z')   {
        return a-'a';
    }
    return a-'A'+26;
}

int main()  {
    freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
    static int p, lis[N][N];
    cin >> p;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                lis[i][j] = 0;
            } else  {
                lis[i][j] = inf;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        char x, y;
        int d;
        cin >> x >> y >> d;
        lis[check(x)][check(y)] = min(lis[check(x)][check(y)], d);
        lis[check(y)][check(x)] = min(lis[check(y)][check(x)], d);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                lis[i][j] = min(lis[i][j], lis[i][k]+lis[k][j]);
                
            }
        }
    }
    int ans;
    int dis = inf;
    for (int i = 26; i < N-1; i++)    {
        if (lis[i][N-1] < dis) {
            ans = i;
            dis = lis[i][N-1];
        }
    }
    cout << char('A'+ans-26) << ' ' << dis << endl;
}