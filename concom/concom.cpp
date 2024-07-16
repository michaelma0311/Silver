/*
ID: michael504
LANG: C++
TASK: concom
*/


#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> owns[101];
int own[101];
bool owned[101];

void dfs(int cur)   {
    if (owned[cur] == true) {
        return;
    } 
    owned[cur] = true;
    for (pair<int, int> i : owns[cur])  {
        own[i.first] += i.second;
        if (own[i.first] > 50)  {
            dfs(i.first);
        }
    }
}

int main()  {
    freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        //cout << x << ' ' << y << ' ' << lis.size() << ' ' << lis[x].size() << endl;
        owns[x].push_back(make_pair(y, z));
        
    }
    for (int i = 0; i < 101; i++) {
        fill(own, own+101, 0);
        fill(owned, owned+101, false);
        dfs(i);
        for (int j = 0; j < 101; j++) {
            if (i != j && owned[j] == true) {
                cout << i+1 << ' ' << j+1 << endl;
            }
        }
    }

}