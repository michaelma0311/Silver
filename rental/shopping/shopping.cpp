/*
ID: michael504
LANG: C++
TASK: shopping
*/
#include <bits/stdc++.h>

using namespace std;


struct special_offer {
    int n;
    int price;             
    struct product {     
        int id;             
        int items;         
    } prod[6];
} so[100];

int code[1000], price[6], many[6];             

                  

int s, ga;                     

int sol[6][6][6][6][6];     

void init() {              
    freopen("shopping.in","r",stdin); 
    cin>>s;
    for (int i=1;i<=s;i++) {
        cin>>so[i].n;
        for (int j=1;j<=so[i].n;j++)
            cin>>so[i].prod[j].id>>so[i].prod[j].items;
        cin>>so[i].price;
    }
    cin>>ga;
    for (int i=1;i<=ga;i++) {
        int tmp;
        cin>>tmp;
        code[tmp]=i; 
        //cout << "TEMPFEMIGWEPNGEWI " << tmp << ' ' << i << endl;
        cin>>many[i];
        cin>>price[i];
    }
}

void solve()    {
    for (int a = 0; a <= many[1]; a++)   {
        for (int b = 0; b <= many[2]; b++)   {
            for (int c = 0; c <= many[3]; c++)   {
                for (int d = 0; d <= many[4]; d++)   {
                    for (int e = 0; e <= many[5]; e++)   {
                        //cout << a << b << c << d << e << endl;
                        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
                            continue;
                        }
                        //cout << "prices " << price[1] << price[2] << price[3] << price[4] << price[5] << ' ' << a << b << c << d << e << endl; 
                        int cur = a*price[1] + b*price[2] + c*price[3] + d*price[4] + e*price[5];
                        //cout << "CUR " << cur << endl;
                        for (int k = 1; k <= s; k++)    {
                            bool can = true;
                            int temp[6];
                            for (int i = 0; i < 6; i++)   {
                                temp[i] = 0;
                            }
                            for (int i = 1; i <= so[k].n; i++)   {
                                temp[code[so[k].prod[i].id]] = so[k].prod[i].items;
                                //cout << "ITEMS "  << ' ' << so[k].prod[i].id << ' ' << so[k].prod[i].items << ' ' << k << endl;
                            }
                            if (temp[1] > a || temp[2] > b || temp[3] > c || temp[4] > d || temp[5] > e)    {
                                can = false;
                            }
                            if (can == true)    {
                                //cout << "ADAD" << a << b << c << d << e << ' ' << "price " << so[k].price << "temps " << temp[1] << temp[2] << temp[3] << temp[4] << temp[5]<< endl;
                                int cur1 = so[k].price + sol[a-temp[1]][b-temp[2]][c-temp[3]][d-temp[4]][e-temp[5]];
                                //cout << cur << ' ' << cur1 << endl;
                                cur = min(cur, cur1);
                            }
                        }
                        sol[a][b][c][d][e] = cur;
                    }
                }
            }
        }
    }
}

int main()  {
    freopen("shopping.out","w",stdout);

    init();
    solve();
    //cout << many[1] << ' ' << many[2] << ' ' << many[3] << ' ' << many[4] << ' ' << many[5] << endl;
    cout << sol[many[1]][many[2]][many[3]][many[4]][many[5]] << endl;
}