/*
ID: michael504
LANG: C++
TASK: fact4
*/
#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);

    int n;
    cin >> n;
    int five = 0;
    int cur = 5;
    int two = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++)    {
        int temp = i;
        while (temp % 2 == 0)   {
            temp /= 2;
            two += 1;
        }
        while (temp%5 == 0) {
            temp /= 5;
            five += 1;
        }
        ans *= temp;
        //cout << ans << ' ' << temp << endl;
        ans %= 10;
    }
    int left = two-five;
    //cout << "ADADAD " << left << endl;
    for (int i = 0; i < left; i++)  {
        ans *= 2;
        ans = ans % 10;
    }
    cout << ans%10 << endl;
}