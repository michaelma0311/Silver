#include<bits/stdc++.h>
using namespace std;

int rp(char c) {
    if (islower(c)) return 26 + c -'a';
    return c - 'A';
}

int lis[52];
int ind[52];
bool visited[52];

    
int main() {
    int t; 
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        string s1, s2; cin >> s1 >> s2;
        if (s1 == s2) {
        return 0;
    }
    
    fill(lis,lis+52,-1);
    fill(visited, visited+52, false);
    fill(ind, ind+52,0);
    
    
    set<int> lets;
    
    for (int i = 0; i < s1.length(); i++) {
        int from = rp(s1[i]);
        int to = rp(s2[i]);
        lets.insert(to);
        if (lis[from] == -1) {
            lis[from] = to;
            ind[to] += 1;
        } else if (lis[from] != to) {
            return -1;
        }
    }
    
    if (lets.size() == 52) {
        return -1;
    }
    
    int ans = 0;
    
    for (int i = 0; i < 52; i++) {
        if (lis[i] == i) {
            lis[i] = -1;
        }
    }
    
    for (int i = 0; i < 52; i++) {
        if (visited[i]) {
            continue;
        }
        if (lis[i] == -1) {
            continue;
        }
    
        vector<int> cycle;
        bool can = true;
        int cur = i;
        while (true) {
            if (lis[cur] == -1) {
                break;
            }
            bool cyc = false;
            for (int j = 0; j < cycle.size(); j++) {
                if (cur == cycle[j]) {
                    cyc = true;
                    if (can) {
                        ans ++;
                    }
                    break;
                }
            }
            if (cyc) {
                break;
            }
            if (visited[cur]) {
                break;
            }
            visited[cur] = true;
            cycle.push_back(cur);
            ans++;
            if (ind[cur] > 1) {
                can = false;
            }
            cur = lis[cur];
        }
    }
    
    cout << ans << endl;
    }
}
