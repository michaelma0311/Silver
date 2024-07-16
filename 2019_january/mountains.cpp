#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> lis;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main()  {
    freopen("mountains.in","r",stdin);
	freopen("mountains.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lis.push_back(make_pair(x, y));
    }
    //cout << "ADAD " << endl;
    sort(lis.begin(), lis.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i+1; j--)   {
            pair<int, int> cur1 = lis[i];
            pair<int, int> cur2 = lis[j];
            if (abs(cur1.first - cur2.first) <= abs(cur1.second - cur2.second)) {
                ans += 1;
                break;
            }
        }
    }
    cout << n-ans << endl;
}