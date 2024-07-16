#include <bits/stdc++.h>

using namespace std;

struct pairs {
	int left, right;
};

bool cmp (const pairs& a, const pairs& b) {
	return a.left < b.left;
}

int main()  {
    freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
    int n;
	cin >> n;
	vector<pairs> arr(n);
    for (int i = 0; i < n; i++) {
		cin >> arr[i].left >> arr[i].right;
	}
    sort(arr.begin(), arr.end(), cmp);
    int ans = 0;
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].right > hi)  {
            lo = max(hi, arr[i].left);
            ans += arr[i].right-lo;
            
            hi = arr[i].right;
        }
    }
    pairs final;
    final.left = arr[n-1].right;
    int ans1 = ans;
    arr.push_back(final);
    hi = 0;
    for (int i = 0; i < n; i++) {
        int curr = min(arr[i+1].left, arr[i].right) - max(arr[i].left, hi);
        ans1 = min(ans1, curr);
        hi = max(hi, arr[i].right);
    }
    ans1 = max(ans1, 0);
    //cout << ans1 << endl;
    int acans = ans-ans1;
    cout << acans << endl;
}