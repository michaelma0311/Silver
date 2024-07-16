
#include <bits/stdc++.h>
using namespace std;

int main()  {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int n;
    int m;
    cin >> n >> m;
    int first[n];
    int second[n];
    int where[m] = {0};
    int sol[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        first[i] = x-1;
        second[i] = y-1;
    }
    int ans = 0;
    for (int i = n-1; i >= 0; i--)  {
        //cout << i << endl;
        int cur = first[i];
        int temp = i;
        while (1)    {
            //cout << "dadadad " << where[cur] << ' ' << cur << endl;
            if (where[cur] == 0)    {
                ans += 1;
                where[cur] = temp;
                //cout << where[cur] << endl;
                break;
            } else if (where[cur] < temp)   {
                break;
            } else  {
                int next = where[cur];
                where[cur] = temp;
                if (cur == second[next])    {
                    break;
                }
                temp = next;
                cur = second[temp];
            }
        }
        //cout << i << endl;
        sol[i] = ans;
    }
    for (int i = 0; i < n; i++) {
        cout << sol[i] << endl;
    }
}
