#include<bits/stdc++.h>
using namespace std;

int main()  {
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    int n;
	vector<vector<int>> cows;
	cin >> n;
	for (int c = 0; c < n; c++) {
		int x, y;
		cin >> x >> y;
		cows.push_back({c, x, y});
	}

	// sort by arrival time
	auto cmp = [](const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	};
	sort(cows.begin(), cows.end(), cmp);
    
    
	int time = 0;
	int cur = 0;
	int longest = 0;
	
	set<vector<int>> wait;
    
    while (cur < n || wait.empty() != true)  {
        if (cur < n && cows[cur][1] <= time) {
			wait.insert(cows[cur]);
			cur++;
        }   else if (wait.empty()) {
			    time = cows[cur][1] + cows[cur][2];
			    cur++;
		} else {
			vector<int> next = *wait.begin();
			longest = max(longest, time - next[1]);
			time += next[2];
			wait.erase(wait.begin());
		}

    }
    cout << longest << endl;
}