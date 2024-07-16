#include <bits/stdc++.h>

using namespace std;

int main()  {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> east;
    vector<pair<int, pair<int, int>>> north;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(0);
        char a;
        int x, y;
        cin >> a >> x >> y;
        if (a == 'E')   {
            east.push_back(make_pair(y, make_pair(x, i)));
        } else  {
            north.push_back(make_pair(x, make_pair(y, i)));
        }
    }
    sort(east.begin(), east.end());
    sort(north.begin(), north.end());
    vector<bool> stop(n);
    for (pair<int, pair<int, int>> i : east) {
        for (pair<int, pair<int, int>> j : north)   {
            int ex = i.second.first;
            int ey = i.first;
            int nx = j.first;
            int ny = j.second.first;
            //cout << ex << ' ' << ey << ' ' << nx << ' ' << ny << endl;
            if (stop[i.second.second] == false && stop[j.second.second] == false && nx > ex && ey > ny)    {
                //cout << "ADdadadadd" << endl;
                if (nx - ex > ey - ny)  {
                    stop[i.second.second] = true;
                    ans[j.second.second] += 1 + ans[i.second.second];
                } else if (ey - ny > nx-ex) {
                    stop[j.second.second] = true;
                    ans[i.second.second] += 1 + ans[j.second.second];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

}