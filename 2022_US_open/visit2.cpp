#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;
vector<int> vals;
int n;
vector<bool> visited;
int ans = 0;
int tempval = INT_MAX;
int tempnum = -1;
int val = 0;
bool dfs(int cur, int prev) {
    if (visited[cur] == true)   {
        return true;
    }
    if (vals[cur] < tempval)    {
        tempnum = cur;
        tempval = vals[cur];
    }
    

}

int main()  {
    cin >> n;
    adj.resize(n);
    vals.resize(n);
    visited.resize(n);
    
    for (int i = 0; i < n; i++) {
        int x, y;
        x -= 1;
        vals[x] = y;
        adj[x].push_back(i);
        adj[i].push_back(x);
        ans += y;
    }
    for (int i = 0; i < n; i++) {
        tempval = INT_MAX
        if (visited[i] == false)    {
            if (dfs(i, -1))
        }
    }
}