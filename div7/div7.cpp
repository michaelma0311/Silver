 #include <bits/stdc++.h>
using namespace std;

int main()  {
    freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    int rem = 0;
    vector<int> cows(7, 100000);
    cows[0] = 0;
     
    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;
        rem = (rem+cur)%7;
        if (cows[rem] == 100000)    {
            cows[rem] = i;
        }   else    {
                ans = max(ans, i-cows[rem]);
        }
    }
    cout << ans << endl;

}