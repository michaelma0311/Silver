#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> x;
set<multiset<int>> sols;

void check_sol(int sum, int b, int c) {
	int a = sum-b-c;
	assert(a > 0 && b > 0 && c > 0);
	set<int> s{0,a,b,c,a+b,b+c,c+a,a+b+c};
	for (int t: x) if (!s.count(t)) return;
	sols.insert({a,b,c});
}
 
void test(int sum) {
	set<int> candidates;
	for (int t: x) {
		if (t > sum) return;
		if (t == 0 || t == sum) continue;
		candidates.insert(min(t,sum-t));
	}
	assert(candidates.size() >= 2);
	int a = *begin(candidates);
	int b = *next(begin(candidates));
	check_sol(sum,a,b);
	check_sol(sum,a,sum-b);
}
 
int solve() {
	cin >> N; 
	x.resize(N); for (int& t : x) cin >> t;
	x.push_back(0);

	sols.clear();
	for (int i = 0; i < (int)x.size(); ++i)
		for (int j = i+1; j < (int)x.size(); ++j)
			test(x[i]+x[j]);
	return (int)sols.size();
}
 
int main() {
	int T; cin >> T;
	while (T--) cout << solve() << "\n";
}