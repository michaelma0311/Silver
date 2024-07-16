#include <bits/stdc++.h>
using namespace std;
int x, y, k, m;
int visited[101][101];
int ans;


void dfs(int x1, int y1, int k1)   {
    ans = min(ans, abs(m-x1-y1));
    if (k1 > 0 && k1 > visited[x1][y1])    {
        visited[x1][y1] = k1;
        
        dfs(x1, y, k1-1);
        dfs(0, y1, k1-1);
        dfs(x, y1, k1-1);
        dfs(x1, 0, k1-1);
        dfs(min(x, x1 + y1), y1 - min(x, x1 + y1) + x1, k1 - 1); 
		dfs(x1 - min(y, y1 + x1) + y1, min(y, y1 + x1), k1 - 1);
    }
}

int main() {
    freopen("pails.in" , "r", stdin);
    freopen("pails.out", "w", stdout);
	cin >> x >> y >> k >> m;
	ans = m; 
	for (int i = 0; i < 101; i++) { 
        for (int j = 0; j < 101; j++) {
            visited[i][j] = -1;  
        }
    }
	dfs(0, 0, k); 
    cout << ans << endl;

}