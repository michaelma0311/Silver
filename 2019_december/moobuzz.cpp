#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("moobuzz.in","r",stdin);
	freopen("moobuzz.out","w",stdout);
    int n;
    cin >> n;
    int rem = (n-1)%8;
    int num = (n-1)/8;
    vector<int> lis = {1, 2, 4, 7, 8, 11, 13, 14};
    int cur = num*15;
    cout << cur+lis[rem] << endl;
}