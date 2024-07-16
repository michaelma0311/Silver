#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int n;
	cin >> n;
    int minc = 0;
    int maxc = 0;
	int cows[100005];
	for (int i = 0; i < n; ++i) {
		cin >> cows[i];
	}
	sort(cows, cows + n);
    if (cows[n-2] - cows[0] == n-2 && cows[n-1] - cows[n-2] > 2)    {
        minc = 2;
    } else if (cows[n-1] - cows[1] == n-2 && cows[1] - cows[0] > 2) {
        minc = 2;

    } else  {
        int cow1 = 0;
        int maxr = 0;
        for (int i = 0; i < n; i++) {
            while (cow1 < n-1 && cows[cow1+1] - cows[i] <= n-1) {
                cow1 += 1;
            }
            int rang = cow1-i+1;
            maxr = max(maxr, rang);
        }
        minc = n-maxr;
    }
    maxc = max(cows[n-2]-cows[0], cows[n-1]-cows[1]) - (n-2);
    cout << minc << endl << maxc << endl;
}
