/*
ID: michael504
LANG: C++
TASK: stamps
*/
#include <bits/stdc++.h>

using namespace std;

const int ma = 10000;

short dp[10000 * (200 + 3) + 3];
int stamps;
int value[200];
int number;


int 
main ()
{

    ifstream filein ("stamps.in");
    filein >> number >> stamps;
    int magest = -1;
    for (int i = 0; i < stamps; ++i) {
	filein >> value[i];
	if (magest < value[i]) {
	    magest = value[i];
	}
    }
    filein.close ();

    for (int i = 0; i <= magest * number + 3; ++i) {
	dp[i] = ma;
    }

    dp[0] = 0;
    for (int i = 0; i < stamps; ++i) {
        for (int j = 0; j <= magest * number; ++j) {
            if (dp[j] < number) {
                if (dp[j + value[i]] > 1 + dp[j]) {
                    dp[j + value[i]] = 1 + dp[j];
                }
            }
        }
    }


    int ans = 0;
    while (dp[ans + 1] <= number) {
	    ++ans;
    }

    ofstream fileout ("stamps.out");
    fileout << ans << endl;
    fileout.close ();

    return (0);
}