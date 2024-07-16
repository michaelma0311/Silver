#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> lis;
bool rwork(int radi, int cur)   {
    int temp = cur;
    int aft = 0;
    while (temp < lis.back())   {
        while (aft+1 < n && temp + radi >= lis[aft+1])  {
            aft += 1;
        }
        if (lis[aft] == temp)    {
            return false;
        }
        temp = lis[aft];
        radi -= 2;
        //cout << temp << endl;
    }
    return true;
}

bool lwork(int radi, int cur)   {
    for (int &i:lis)    {
        i *= -1;
    }
    reverse(lis.begin(), lis.end());
    bool p;
    p = rwork(radi, -cur);
    reverse(lis.begin(), lis.end());
    for (int &i:lis)    {
        i *= -1;
    }
    return p;
}


int main()  {
    freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
    cin >> n;
    lis.resize(n);
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        lis[i] = cur*2;
        //cout << lis[i] << endl;
    }
    sort(lis.begin(), lis.end());
    int lo = 0;
    int hi = 2000000000;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        int left = lis.front();
        int right = lis.back();
        while (left < right)    {
            int smid = left + (right-left)/2;
            if (rwork(mid, smid) == true) {
                right = smid;
            } else  {
                left = smid+1;
            }
            //cout << left << ' ' << right << endl;
        }
        if (lwork(mid, left) == true)  {
            hi = mid;
        } else  {
            lo = mid+1;
        }
        //cout << lo << ' ' << hi << endl;
    }

    cout << lo/2 << '.' << (lo%2 ? 5 : 0) << endl;
}