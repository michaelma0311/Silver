#include <bits/stdc++.h>
using namespace std;

int main()  {
    freopen("gates.in" , "r", stdin);
    freopen("gates.out", "w", stdout);
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<pair<pair<int, int>, pair<int, int>>> edg;
	set<pair<int, int>> nod;
	int ans = 0;
	pair<int, int> bef{0, 0};
	nod.insert(bef);
    for (int i = 0; i < n; i++) {
        int x = bef.first;
        int y = bef.second;
        if (str[i] == 'N')  {
            x += 1;
        } else if (str[i] == 'S')   {
            x -= 1;
        } else if (str[i] == 'E')   {
            y -= 1;
        } else if (str[i] == 'W')   {
            y += 1;
        }
        if (nod.find({x, y}) != nod.end() && edg.find({{x, y}, bef}) == edg.end())    {
            ans += 1;
        }
        edg.insert({bef, {x, y}});
        edg.insert({{x, y}, bef});
		nod.insert({x, y});
			  
		bef.first = x;
		bef.second = y;
    }
    cout << ans << endl;
}