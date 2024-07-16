/*
ID: michael504
LANG: C++
TASK: fracdec
*/
#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);

    int n, d;
    cin >> n >> d;
    vector<int> rems;
    map<int, int> pos;
    if (n%d == 0)   {
        cout << n/d << ".0" << endl;
    } else  {
        cout << n/d << '.';
        n = n%d;
        while (true)    {
            int temp = n*10;
            int rem = temp/d;
            temp = temp%d;
            if (n == 0) {
                for (int i = 0; i < rems.size(); i++)   {
                    cout << rems[i];
                }
                cout << endl;
                break;
            }
            if (pos.find(n) != pos.end())   {
                int sad = 76;
                for (int i = 0; i < pos[n]; i++)    {
                    cout << rems[i];
                    sad -= 1;
                }
                cout << "(";
                sad -= 1;
                for (int i = pos[n]; i < rems.size(); i++)   {
                    if (((i/sad) == 0 && i % sad == 0) || (i/sad) != 0 && i % 76 == 0)  {
                        cout << rems[i] << endl;
                    } else  {
                        cout << rems[i];
                    }
                }
                cout << ")" << endl;
                break;
            } else  {
                pos[n] = rems.size();
                rems.push_back(rem);
                n = temp;
            }
        }
    }
}