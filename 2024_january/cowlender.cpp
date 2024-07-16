#include <bits/stdc++.h>

using namespace std;
long long tem;
unordered_set<long long> solve(long long n) {
    unordered_set<long long> tempre;
    for (long long i = 1; i <= static_cast<long long>(sqrt(n)); ++i) {
        if (n % i == 0) {
            if (tem >= i)   {
                tempre.insert(i);
            }
            if (tem >= (n/i))   {
                tempre.insert(n/i);
            }
        }
    }
    return tempre;
}

int main() {
    freopen("cowlender.in", "r", stdin);
    long long n;
    cin >> n;

    vector<long long> lis;
    for (long long i = 0; i < n; ++i) {
        long long num;
        cin >> num;
        lis.push_back(num);
    }

    sort(lis.begin(), lis.end());
    lis.erase(unique(lis.begin(), lis.end()), lis.end());
    long long cur = lis.size();
    tem = static_cast<long long>(*min_element(lis.begin(), lis.end()))/4 ;
    if (cur <= 3) {
        long long g = static_cast<long long>(*min_element(lis.begin(), lis.end())/4);
        cout << static_cast<long long>(g*(g + 1) / 2) << endl;
    } else {
        map<long long, long long> dicti;
        for (long long i = 0; i < cur; ++i) {
            for (long long j = i + 1; j < cur; ++j) {
                if (dicti.find(lis[j] - lis[i]) == dicti.end()) {
                    dicti[lis[j] - lis[i]] = 0;
                }
                dicti[lis[j] - lis[i]] += 1;
            }
        }
        vector<long long> p;
        for (const auto& i : dicti) {
            if (cur - 3 <= i.second) {
                p.push_back(i.first);
            }
        }
        unordered_set<long long> g;
        for (long long i : p) {
            auto curtem = solve(i);
            g.insert(curtem.begin(), curtem.end());
        }
        long long ans = 0;
        if (tem >= 3)   {
            ans += 3;
        }
        if (tem >= 2)   {
            ans += 2;
        }
        if (tem >= 1)   {
            ans += 1;
        }
        for (long long i : g) {
            if (i == 1 || i == 2 || i == 3) {
                continue;
            }
            ans += i;
        }
        cout << ans << endl;
    }
}