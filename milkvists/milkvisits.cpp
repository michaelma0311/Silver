#include <bits/stdc++.h>

using namespace std;
const int r = 1000000;
int start, dest;
char type;
int n, m;
int com[r];
int cur;
bool lis[r];
vector<int> adj[r];



void dfs(int rn) {
    if (com[rn])    {
        return;
    }
    com[rn] = cur;
    for (auto i : adj[rn])  {
        if (lis[i] == lis[rn])  {
            dfs(i);
        }
    }

}
int main()  {
    freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    string p;
    cin >> p;
    for (int i = 1; i <= n; i++)    {
        if (p[i-1] == 'G')  {
            lis[i] = true;
        } else  {
            lis[i] = false;
        }
    }
    //cout << "adwda" << endl;
    for (int i = 0; i < n-1; i++)   {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)    {
        if (com[i] == false)   {
            cur += 1;
            dfs(i);
        }
    }
    //cout << "dawda" << endl;
    //cout << sizeof(com) << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        char type;
        cin >> x >> y >> type;
        if ((lis[x] == true && type == 'G') || (lis[x] == false && type == 'H') || com[x] != com[y])    {
            cout << 1;
        } else  {
            cout << 0;
        }
    }
    cout << endl;
}