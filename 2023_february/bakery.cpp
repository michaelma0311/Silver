#include <bits/stdc++.h>

using namespace std;

int n, t1, t2;
vector<int> A;
vector<int> B;
vector<int> C;
bool solve(int mid) {
    int left = max(1, t1-mid);
    int right = min(t1+t2-mid-1, t1);
    for (int i = 0; i < n; i++) {
        int a, b, c = A[i], B[i], C[i];
        int cur = t1+t2-mid;
        if (b-a > 0)    {
            int nxt = (b*cur-c+(b-a-1));
            int cur = nxt/(b-a);
            left = max(left, cur);
        } else if (a-b > 0)    {
            int cur = (c-b*cur)/(a-b);
            right = min(right, cur);
        } else  {
            if (a*cur > c) {
                return false;
            }
        }
    }
    return (left <= right);
}

int main()  {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n >> t1 >> t2;
        A.resize(n);
        B.resize(n);
        C.resize(n);
        A.clear();
        B.clear();
        C.clear();
        for (int i = 0; i < n; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        

        int l = 0;
        int h = t1+t2-2;
        while (h > l)   {
            int mid = (l+h)/2;
            //cout << "adada " << mid << endl;
            if (solve(mid) == true) {
                h = mid;
            } else  {
                l = mid+1;
            }
        }
        cout << l << endl;
    }
    
}