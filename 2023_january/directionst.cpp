#include <bits/stdc++.h>

using namespace std;
int n;
char dir[1501][1501];
int nums[1505][1505];
long long sol = 0;
vector<int> visited;
vector<int> adj;
vector<vector<int>> prevl;

vector<int> cycnum;
void fl(int x, int y, long long prev, int num, int count)   {
    long long key = x*n+y;
    //cout << visited[key] << " adadadad " << key << endl;
    if (visited[key] != 0)  {
        sol += (count-1)*cycnum[visited[key]-1];
        cycnum.push_back(cycnum[visited[key]-1]);
        return;
    }
    //cout << "loop " << key << ' ' << dir[x][y] << endl;
    visited[key] = num;
    prevl[key].push_back(prev);
    //cout << "key " << key << ' ' << prev << endl;

    if (dir[x][y] == 'R')   {
        if (y+1 >= n) {
            //cout << "adadasdada" << endl;
            cycnum.push_back(nums[x][y+1]);
            sol += count*nums[x][y+1];
            return;
        } else  {
            adj[key] = key+1;
            fl(x, y+1, key, num, count+1);
        }
    } else  {
        if (x+1 >= n) {
            cycnum.push_back(nums[x+1][y]);
            sol += count * nums[x+1][y];
            return;
        } else  {
            adj[key] = key+n;
            fl(x+1, y, key, num, count+1);
        }
    }
}
long long am(int cur, int num) {
    if (cur == -1)  {
        return 0;
    }
    //cout << cur << " hihihihi " << num << endl;
    visited[cur] = num;
    long long ans = 1;
    for (int i = 0; i < prevl[cur].size(); i++) {
        //cout << prevl[cur][i] << "func" << endl;
        ans += am(prevl[cur][i], num);
    }
    return ans;
}
int main()  {
    cin >> n;
    visited.resize(n*n+1);
    adj.resize(n*n+1);
    prevl.resize(n*n+1, {});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dir[i][j];
        }
        cin >> nums[i][n];
    }
    for (int i = 0; i < n; i++) {
        cin >> nums[n][i];
    }
    int um = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long key = i*n+j;
            //cout << visited[key-1] << " adadad" << endl;
            //cout << "sol " << sol << endl; 
            if (visited[key] == 0)    {
                //cout << key << endl;
                fl(i, j, -1, um, 1);
                um += 1;
            }
        }
    }
    
    cout << sol << endl;
    /*for (int i : cycnum)    {
        cout << "adada " << i << endl;
    }
    */
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        long long key = x*n+y;
        prevl[adj[key]].erase(remove(prevl[adj[key]].begin(), prevl[adj[key]].end(), key), prevl[adj[key]].end());
        //cout << "inside " << cycnum[visited[key]-1] << ' ' << p << ' ' << dir[x][y] << ' ' << visited[key] << endl;
        int p = 0;
        int pr = cycnum[visited[key]-1];
        //cout << "pr " << visited[key]-1 << endl;
        if (dir[x][y] == 'D')   {
            dir[x][y] = 'R';
            if (y+1 >= n)   {
                cycnum.push_back((nums[x][y+1]));
                visited[key] = cycnum.size();
                p = am(key, visited[key]);
                //cout << "last" << endl;
            } else  {
                adj[key] = key+1;
                prevl[key+1].push_back(key);
                p = am(key, visited[adj[key]]);
                //cout << "still" << endl;
            }
        } else  {
            dir[x][y] = 'D';
            if (x+1 >= n) {
                cycnum.push_back((nums[x+1][y]));
                visited[key] = cycnum.size();
                p = am(key, visited[key]);
                //cout << "loast" << endl;
            } else  {
                adj[key] = key+n;
                prevl[key+n].push_back(key);
                visited[key] = visited[adj[key]];
                p = am(key, visited[adj[key]]);
            }
        }
        //cout << "out " << visited[key]-1 << endl;
        //cout << "putside " << cycnum[visited[key]-1] << ' ' << p << ' ' << visited[key]<< endl;
        //cout << "outside " << p << ' ' << pr << ' ' << cycnum[visited[key]-1] << endl;
        sol += cycnum[visited[key]-1] * p;
        sol -= pr*p;
        
        cout << sol << endl;
    }
}