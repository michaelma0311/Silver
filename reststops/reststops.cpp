#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("reststops.in","r",stdin);
	freopen("reststops.out","w",stdout);

	int trail_len;
	int stop_num;
	int f_rate;
	int b_rate;
	cin >> trail_len >> stop_num >> f_rate >> b_rate;

	vector<int> x(stop_num);
	vector<int> c(stop_num); 
	for (int i = 0; i < stop_num; i++) {
        cin >> x[i] >> c[i];
    }

	vector<bool> good(stop_num);
	int max_tastiness = 0;
	for (int i = stop_num - 1; i >= 0; i--) {
		if (c[i] > max_tastiness) {
			good[i] = true;
			max_tastiness = c[i];
		}
	}

	long long temp1 = 0;
	long long ans = 0;
	for (int i = 0; i < stop_num; i++) {
		if (good[i]) {
			long long cur = x[i] - temp1;
			long long f_time = cur * f_rate;
			long long b_time = cur * b_rate;
			long long rest_time = f_time - b_time;
			ans += rest_time * c[i];
			temp1 = x[i];
		}
	}

	cout << ans << endl;
}
