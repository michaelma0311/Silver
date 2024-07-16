#include<bits/stdc++.h>
using namespace std;


bool cmp(const pair<int, int>&a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main()  {
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> cords(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cords[i].first = x;
        cords[i].second = y;
    }
    sort(cords.begin(), cords.end(), cmp);
   
    int ans = 0;
    int x1, y1;
    int x2, y2;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i+1; j--)   {
            x1 = cords[i].first;
            y1 = cords[i].second;
            x2 = cords[j].first;
            y2 = cords[j].second;
            if (abs(x2-x1) <= abs(y2-y1))  {
                ans += 1;
                break;
            }
        }
    }
    cout << n-ans << endl;
}