/*
ID: michael504
LANG: C++
TASK: frac1
*/

#include <bits/stdc++.h>

using namespace std;

int n;

/* print the fractions of denominator <= n between n1/d1 and n2/d2 */
void solve(int n1, int d1, int n2, int d2) {
	if(d1+d2 > n)	/* cut off recursion */
		return;
    //cout << n1 << ' ' << n2 << ' ' << d1 << ' ' << d2 << endl;
	solve(n1,d1, n1+n2,d1+d2);
    cout << n1+n2 << "/" << d1+d2 << endl;
	solve(n1+n2,d1+d2, n2,d2);
}

int main(void)
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);

	cin >> n;

	cout << "0/1" << endl;
	solve(0,1, 1,1);
	cout << "1/1" << endl;
}