#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n;
    cin >> n;
    for (int q = 0; q < n; q++) {
        long long a, b;
        cin >> a >> b;
        vector<long long> first;
        vector<long long> second;
        if (a == b) {
            cout << 0 << endl;
        } else  {
            
            while (a > 1)  {
                first.push_back(a);
                if (a % 2 == 0) {
                    a /= 2;
                } else  {
                    a += 1;
                }
            }
            first.push_back(1);
            while (b > 1)  {
                //cout << "second " << b << endl; 
                second.push_back(b);
                if (b % 2 == 0) {
                    b /= 2;
                } else  {
                    b -= 1;
                }
            }
            second.push_back(1);
            long long ans = 1000000000;
            long long temp = 0;
            for (int i = 0; i < first.size(); i++)  {
                for (int j = 0; j < second.size(); j++) {
                    if (first[i] <= second[j])   {
                        //cout << second[j] << ' ' << first[i] << endl;
                        temp = second[j] - first[i] + i + j;
                        ans = min(ans, temp);
                    }
                }
            }
            cout << ans << endl;
        }
    }
}