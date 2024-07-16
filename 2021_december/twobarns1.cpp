#include <bits/stdc++.h>
using namespace std;
 
void dfs(const vector<vector<int>>& edges, vector<int>& lis, const int currv, const int id) {
  for(int child: edges[currv]) {
    if(lis[child] != id) {
      lis[child] = id;
      dfs(edges, lis, child, id);
    }
  }
}
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  vector<int> lis(n);
  iota(lis.begin(), lis.end(), 0);
  for(int i = 0; i < n; i++) {
    if(lis[i] == i) {
      dfs(edges, lis, i, i);
    }
  }
  if(lis[0] == lis[n-1]) {
    cout << "0\n";
    return;
  }
  vector<vector<int>> curn(n);
  for(int i = 0; i < n; i++) {
    curn[lis[i]].push_back(i);
  }
  long long ans = 1e18;
  vector<long long> temp1(n, 1e9);
  vector<long long> temp2(n, 1e9);
  int srcidx = 0;
  int dstidx = 0;
  for(int i = 0; i < n; i++) {
    while(srcidx < curn[lis[0]].size()) {
      temp1[lis[i]] = min(temp1[lis[i]], (long long)abs(i - curn[lis[0]][srcidx]));
      if(curn[lis[0]][srcidx] < i) srcidx++;
      else break;
    }
    if(srcidx) srcidx--;
    while(dstidx < curn[lis[n-1]].size()) {
      temp2[lis[i]] = min(temp2[lis[i]], (long long)abs(i - curn[lis[n-1]][dstidx]));
      if(curn[lis[n-1]][dstidx] < i) dstidx++;
      else break;
    }
    if(dstidx) dstidx--;
  }
  for(int i = 0; i < n; i++) ans = min(ans, temp1[i]*temp1[i] + temp2[i]*temp2[i]);
  cout << ans << "\n";
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}