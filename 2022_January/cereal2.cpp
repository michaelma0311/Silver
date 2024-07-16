#include <bits/stdc++.h>
 
using namespace std;
 
struct edge {
    int cow; // which cow's choice 
    int to;
    bool tof;
 
    edge() {};
    edge(int cow, int to, bool tof) : cow(cow), to(to), tof(tof) {};
};
 
int N, M;
 
vector<edge> adj[100001];
bool visited_cycle[100001]; 
bool visited[100001]; 
bool gets_cereal[100001]; 
 
int hungry_cows = 0;
queue<int> lis;
int ign = -1;
int first_cereal = -1; 
 
void solve(int cur, int prev = -1) {
    visited_cycle[cur] = true; 
 
    for (edge next : adj[cur]) {
        if (visited_cycle[next.to]) {
            if (first_cereal == -1 && next.to != prev) {
                if (next.tof) {
                    first_cereal = next.to; 
                } else {
                    first_cereal = cur;
                }
                
                ign = next.cow; 
                lis.push(next.cow);
                gets_cereal[next.cow] = true;
            }
        } else {
            solve(next.to, cur);
        }
    }
}
 
 
void dfs(int cur) {
    visited[cur] = true;
    for (edge next : adj[cur]) {
        if (!visited[next.to] && next.cow != ign) { 
            gets_cereal[next.cow] = true;
            lis.push(next.cow);
            dfs(next.to);
        }
    }
}
 
 
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(edge(i+1, b, false));
        adj[b].push_back(edge(i+1, a, true));
    }
 
    for (int i = 1; i <= M; ++i) {
        first_cereal = -1;
        ign = -1;
        if (!visited[i]) {
            solve(i);
           
            if (first_cereal > 0) {
                dfs(first_cereal);
            } else {
                dfs(i);
            }
        }
    }
 
    for (int i = 1; i <= N; ++i) {
        if (!gets_cereal[i]) {
            ++hungry_cows;
            lis.push(i);
        } 
    }
 
    cout << hungry_cows << endl;
    while (!lis.empty()) {
        cout << lis.front() << endl; 
        lis.pop();
    }
 
    return 0;
}