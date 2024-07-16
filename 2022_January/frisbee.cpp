#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n;
    cin >> n;
    int lis[n];
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
    }
    long long ans;
    stack<int> sta;
    for (int i = 0; i < n; i++) {
        while (sta.empty() == false && lis[i] > lis[sta.top()]) {
            ans += i-sta.top()+1;
            sta.pop();
        }
        if (sta.empty() == false)   {
            ans += i-sta.top()+1;
        }
        sta.push(i);
    }
    cout << ans << endl;
}