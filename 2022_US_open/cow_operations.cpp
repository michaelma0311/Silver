#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> prefc(n + 1), prefo(n + 1), prefw(n + 1);

    for (int i = 0; i < n; i++) {
        prefc[i + 1] = prefc[i];
        prefo[i + 1] = prefo[i];
        prefw[i + 1] = prefw[i];
        if (s[i] == 'C') {
            prefc[i + 1]++;
        } else if (s[i] == 'O') {
            prefo[i + 1]++;
        } else {
            prefw[i + 1]++;
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        int amc = prefc[y] - prefc[x - 1];
        int amo = prefo[y] - prefo[x - 1];
        int amw = prefw[y] - prefw[x - 1];

        if ((amc + amo) % 2 == 1 && (amo + amw) % 2 == 0) {
            cout << 'Y';
        } else {
            cout << 'N';
        }
    }

    cout << endl;

    return 0;
}