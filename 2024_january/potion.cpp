#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> lis;
vector<vector<int>> child;
vector<int> parent;
vector<int> amch;
vector<int> ended;
vector<int> runn;
vector<int> amin;
vector<int> tem;
int calc(int cur)   {
    if (child[cur].size() == 0) {
        amch[cur] = 0;
        return 1;
    }
    for (int i : child[cur])    {
        amch[cur] += calc(i);
    }
    return amch[cur];
}

void dfs(int cur)   {
    //cout << "cur " << cur << endl;
    int ma = INT_MAX;
    int ind = -1;
    if (child[cur].size() == 0)  {
        ended[cur] = true;
        return;
    }
    for (int i : child[cur])    {
        if (amin[i] < ma)  {
            ind = i;
            ma = amin[i];
        }
    }
    if (ind == -1)  {
        return;
    }
    //cout << "INEHREE " << ind << ' ' << runn[ind] << ' ' << amch[ind]<< endl;
    if (runn[ind] + 1 >= amch[ind]) {
        ended[ind] = true;
        //cout << "ADADAD " << ind << endl;
    }
    runn[ind] += 1;
    dfs(ind);

}
int calc2(int cur) {
    if (find(lis.begin(), lis.end(), cur) != lis.end()) {
        amin[cur] += 1;
    }
    if (child[cur].size() == 0) {
        return amin[cur];
    }
    for (int i : child[cur])    {
        amin[cur] += calc2(i);
    }
    return amin[cur];
}
int main()  {
    cin >> n;
    tem.resize(n);
    child.resize(n);
    parent.resize(n);
    amch.resize(n);
    ended.resize(n);
    runn.resize(n);
    amin.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tem[i];
        tem[i] -= 1;
    }
    for (int i = 0; i < n-1; i++)   {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        child[x].push_back(y);
        parent[y] = x;
    }
    parent[0] = -1;
    int mi = calc(0);
    //cout << mi << endl;
    for (int i = 0; i < mi; i++)    {
        lis.push_back(tem[i]);
    }
    calc2(0);
    //cout << endl;
    
    /*for (int i = 0; i < n; i++) {
        cout << amch[i] << ' ' << amin[i] << endl;
    }
    */
    int ans = 0;
    for (int i = 0; i < mi; i++)    {
        int c = lis[i];
        int tec = lis[i];
        //cout << c << ' ' << ended[c] << endl;
        if (ended[c] == false)    {
            ans += 1;
            while (c != 0)    {
                if (runn[c] + 1 >= amch[c]) {
                    ended[c] = true;
                } 
                runn[c] += 1;
                c = parent[c];
                //cout << cur << endl;
            }
            dfs(tec);
        } else  {
            dfs(0);
        }
    }
    cout << ans << endl;
}