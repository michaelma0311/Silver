#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n, c;
    cin >> c >> n;
    vector<int> teams(n);
    vector<int> ans(1<<c, -1);
    queue<int> lis;
    
    for (int i = 0; i < n; i++) {
        string cur; 
        cin >> cur;
        int x = 0;
        int inv = 0;
        for (int j = 0; j < c; j++) {
            x = 2 * x + (cur[j] == 'G');
            inv = 2 * inv + (cur[j] == 'H');
        }
        teams[i] = x;
        ans[inv] = 0;
        lis.push(inv);
    }
    
    while (!lis.empty()) {
        int cur = lis.front();
        lis.pop();
        for (int i = 0; i < c; i++) {
            int temp = cur ^ (1 << i);
            //cout << temp << endl;
            if (ans[temp] == -1) {
                lis.push(temp);
                ans[temp] = ans[cur]+1;

            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c-ans[teams[i]] << endl;
    }
}