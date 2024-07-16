#include <bits/stdc++.h>

using namespace std;

long long dp[19][50][2][2]; 
string num;

void reset() {
	for (int i = 0; i < 19; i++)    {
        for (int j = 0; j < 50; j++)    {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}
long long solve_dp(int pos, int k, bool tight, bool started, int targ, int targ2) {
	if (pos == num.size()) {
		if (!started) { 
            return 0;
        }
		if (targ2 != -1) {
			if (k == 20) {
				return 1;
			} else {
				return 0;
			}
		}
		if (k >= 20) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[pos][k][tight][started] != -1) { 
        return dp[pos][k][tight][started];
    }

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		int digit_diff = num[pos] - '0';
		if (!tight && i > digit_diff) {
            break;
        }
		bool is_tight = tight;
		if (i < digit_diff) { 
            is_tight = true; 
        }
		bool is_started = started || i != 0;
		if (is_started && targ2 != -1 && i != targ && i != targ2) { 
            continue; 
        }

		int new_k = k;
		if (is_started) {
			if (targ == i) {
				new_k = k + 1;
			} else {
				new_k = k - 1;
			}
		}
		ans += solve_dp(pos + 1, new_k, is_tight, is_started, targ, targ2);
	}
	return dp[pos][k][tight][started] = ans;
}
long long count_interesting_to(long long ubound) {
	num = to_string(ubound);
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		reset();
		ans += solve_dp(0, 20, false, false, i, -1);
	}

	long long duplicates = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			reset();
			duplicates += solve_dp(0, 20, false, false, i, j);
		}
	}
	return ans - (duplicates / 2);
}

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);

	long long X, Y;
	cin >> X >> Y;
	cout << count_interesting_to(Y) - count_interesting_to(X - 1) << endl;
}
