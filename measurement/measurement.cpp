#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("measurement.in" , "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, g;
    cin >> n >> g;
    vector<vector<int>> lis(n);
    for (auto &p : lis) {
        int day, id, milk;
        cin >> day >> id >> milk;
        p = vector<int>({day, id, milk});
    }
    sort(lis.begin(), lis.end());
    //cout << lis[0][0] << endl;
    int ans = 0;
    int most = 0;
    int count = 0;
    map<int,int> t; 
    multiset<int> milk;
    for (int i = 1; i <= n; i++) {
        t[i] = 0;
        milk.insert(0);
    }
    for (int i = 0; i < n; i++) {
        //cout << lis[i][0] << endl;
        int cur = lis[i][1];
        int add = lis[i][2];
        //cout << "dawdada" << endl;
        int old = t[cur];
        //cout << 'd' << endl;
        milk.erase(milk.find(old));
        //cout << 'a' << endl;
        t[cur] += add;
        milk.insert(t[cur]);
        if (t[cur] > most)  {
            if (count != 1 || old != most)  {
                ans += 1;
            }
            count = 1;
            most = t[cur];
        } else if (t[cur] == most)  {
            count += 1;
            ans += 1;
        } else if (old == most) {
            most = *milk.rbegin();
            int prev = count-1;
            count = milk.count(most);
            if (prev != 0 || count != 1 || t[cur] != most)  {
                ans += 1;
            }
        }  
    }
    cout << ans << endl;
}