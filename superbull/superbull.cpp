#include <bits/stdc++.h>

using namespace std;

vector<int> e;

void init(int n) { e = vector<int>(n, -1); }
int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
bool sameSet(int x, int y) { return get(x) == get(y); }
int size(int x) { return -e[get(x)]; }
bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
}

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cur = nums[i] ^ nums[j];
            edges.push_back(make_pair(cur, make_pair(i, j)));
        }
    }
    init(n);
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());
    int ans = 0;
    int elim = 0;
    for (auto i : edges) {
        int w = i.first;
        int x = i.second.first;
        int y = i.second.second;
        if (unite(x, y)) {
            elim += 1;
            ans += w;
            if (elim == n - 1) {
                cout << ans << endl;
                break;
            }
        }
    }
}