#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> lefts(n + 1);
    vector<int> rights(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> lefts[i] >> rights[i];
    }

    vector<char> lis(m);

    for (int index = 0; index < m; index++) {
        cin >> lis[index];
    }

    vector<int> temp(n + 1);

    for (int i = 1; i <= n; i++) {
        int next = i;

        for (char indc: lis) {
            if (indc == 'L') {
                next = lefts[next];
            }

            else {
                next = rights[next];
            }
        }

        temp[i] = next;
    }

    int lo = 1;
    int hi = 1;
    bool start = true;
    
    while ((lo != hi) || start) {
        lo = temp[lo];
        hi = temp[temp[hi]];
        start = false;
    }

    lo = 1;
    vector<int> root;

    while (lo != hi) {
        root.push_back(lo);
        lo = temp[lo];
        hi = temp[hi];
    }

    if (k < root.size()) {
        cout << root[k] << "\n";
        return 0;
    }

    k -= root.size();

    vector<int> cycle;
    start = true;

    while ((lo != hi) || start) {
        cycle.push_back(lo);
        lo = temp[lo];
        start = false;
    }

    k %= cycle.size();
    cout << cycle[k];
    return 0;
}