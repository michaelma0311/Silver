#include <bits/stdc++.h>

using namespace std;

int main()  {
    int n;
    cin >> n;
    long long lis[n];
    vector<long long> temp;
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
        temp.push_back(lis[i]);
    }
    sort(temp.begin(), temp.end());
    vector<long long> prex;
    prex.push_back(0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        prex.push_back(prex[i-1]+temp[i-1]);
        //cout << prex[i] << endl;
        ans += i*temp[i-1];
    }
    int q;
    cin >> q;
    for (int g = 0; g < q; g++) {
        long long x, y;
        cin >> x >> y;
        long long rem = lis[x-1];
        long long num = lower_bound(temp.begin(), temp.end(), rem) - temp.begin();
        if (rem == y)   {
            cout << ans << endl;
            continue;
        }
        long long sol = ans;
        sol -= (rem*(num + 1));
        //cout << "sol " << sol << endl;
        long long fir = lower_bound(temp.begin(), temp.end(), y)-temp.begin();
        fir += 1;
        if (rem > y)    {
            //cout << "y " << y << ' ' << fir << ' ' << prex[num] << ' ' << prex[fir-1] << endl;
            sol += y*fir;
            sol += prex[num] - prex[fir-1];
        } else  {
            //cout << "x " << y << ' ' << fir << ' ' << prex[num] << ' ' << prex[fir-1] << endl;
            fir -= 1;
            sol += y*fir;
            sol -= prex[fir] - prex[num+1];
        }
        cout << sol << endl;
    }
}
