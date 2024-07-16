
#include <bits/stdc++.h>
using namespace std;
struct edge {
    int cow; 
    int to;
    bool fir;
 
};
int N, M;
 
vector<edge> adj[100001];
bool vcyc[100001]; 
bool visited[100001];
bool cereal[100001]; 
 
int ans = 0;
queue<int> lis;
int ign = -1;
int first = -1;

void cycle(int cur, int prev = -1) {
    vcyc[cur] = true; 
 
    for (edge next : adj[cur]) {
        if (vcyc[next.to]) {
            if (first == -1 && next.to != prev) {
                if (next.fir) {
                    first = next.to; 
                } else {
                    first = cur;
                }
                
                ign = next.cow; 
                lis.push(next.cow);
                cereal[next.cow] = true;
            }
        } else {
            cycle(next.to, cur);
        }
    }
}
 

void dfs(int cur)   {
    //cout << "dfs" << endl;
    visited[cur] = true;
    for (edge i : adj[cur]) {
        if (!visited[i.to] && i.cow != ign)  {
            cereal[i.cow] = true;
            lis.push(i.cow);
            dfs(i.to);
        }
    }
}

int main()  {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(edge{i+1, b, false});
        adj[b].push_back(edge{i+1, a, true});
    }
    for (int i = 1; i <= M; ++i) {
        first = -1;
        ign = -1;
        if (!visited[i]) {
            cycle(i);
           
            if (first > 0) {
                dfs(first);
            } else {
                dfs(i);
            }
        }
    }
    for (int i = 1; i <= N; i++)    {
        if (cereal[i] == false) {
            ans += 1;
            lis.push(i);
        }
    }
    cout << ans << endl;
    while (lis.empty() == false)    {
        cout << lis.front() << endl;
        lis.pop();
    }
}
