#include <bits/stdc++.h>

using namespace std;

void solve()    {
    int n, k;
    cin >> n >> k;
    vector<int> ttube1;
    vector<int> ttube2;
    stack<int> tube1;
    stack<int> tube2;
    stack<int> tube3;
    int type = -1;
    string s1, s2;
    cin >> s1 >> s2;
    bool endsame = false;
    int start1;
    
    //cout << s1 << ' ' << s2 << endl;
    for (int i = 0; i < n; i++) {
        int x = s1[i]-'0';
        if (i == 0) {
            start1 = x;
        }
        //cout << x << endl;
        if (type == -1) {
            type = x;
        } else  {
            if (type != x)  {
                ttube1.push_back(type);
                type = x;
                //cout << type << endl;
            }
        }
    }
    int start2;
    //cout << "SECOND" << endl;
    vector<pair<int, int>> direcs;
    ttube1.push_back(type);
    type = -1;
    for (int i = 0; i < n; i++) {
        int y = s2[i]-'0';
        if (i == 0) {
            start2 = y;
        }
        //cout << y << endl;
        if (type == -1) {
            type = y;
        } else  {
            if (type != y)  {
                ttube2.push_back(type);
                type = y;
                //cout << type << endl;
            }
        }
    }
    ttube2.push_back(type);
    if (start1 == start2)    {
        start1^=3;
        tube1.push(start1);
    }
    for (int i : ttube1)    {
            tube1.push(i);
        }
    for (int i : ttube2)    {
        tube2.push(i);
    }
    //cout << start1 << ' ' << start2 << endl;
    //cout << tube1.size() << ' ' << tube2.size() << ' ' << tube2.top()<< endl;
    int ans = 0;
    bool tof1 = false;
    bool tof2 = false;
    if (tube2.size() == 1)  {
        tof2 = true;
    }
    if (tube1.size() == 1)  {
        tof1 = true;
    }
    while ((tof1 == false || tof2 == false))  {
        int cur1 = tube1.top();
        int cur2 = tube2.top();
        //cout << cur1 << ' ' << cur2 << ' ' << tof1 << ' ' << tof2 << endl;
        if (cur1 == cur2) {
            if (tof1 == true)   {
                ans += 1;
                direcs.push_back(make_pair(2, 1));
                tube2.pop();
            } else if (tof2 == true)    {
                ans += 1;
                direcs.push_back(make_pair(1, 2));
                tube1.pop();
            } else  {
                if (cur1 == start1) {
                    ans += 1;
                    direcs.push_back(make_pair(1, 2));
                    tube1.pop();
                } else  {
                    ans += 1;
                    direcs.push_back(make_pair(2, 1));
                    tube2.pop();
                }
            }
            
        } else  {
            if (tof1 == false && tof2 == false) {
                if (tube3.empty() == true || cur1 == tube3.top())   {
                    ans += 1;
                    direcs.push_back(make_pair(1, 3));
                    tube1.pop();
                    if (tube3.empty())  {
                        tube3.push(cur1);
                    }
                    //tube3.push(cur1);
                } else  {
                    ans += 1;
                    direcs.push_back(make_pair(2, 3));
                    tube2.pop();
                    if (tube3.empty())  {
                        tube3.push(cur2);
                    }
                    //tube3.push(cur2);
                }
            } else if (tof2 == true)  {
                ans += 1;
                direcs.push_back(make_pair(1, 3));
                tube1.pop();
                if (tube3.empty() == true || cur1 != tube3.top())   {
                    tube3.push(cur1);
                }
                
            } else if (tof1 == true)   {
                ans += 1;
                direcs.push_back(make_pair(2, 3));
                tube2.pop();
                if (tube3.empty() == true || cur2 != tube3.top())   {
                    tube3.push(cur2);
                }
            }
        }
        if (tube1.size() == 1)  {
            tof1 = true;
        }
        if (tube2.size() == 1)  {
            tof2 = true;
        }
    }
    //cout << ans << endl;
    int bot = 1;
    
    if (tof1 == true && tof2 == true && tube1.top() == tube2.top()) {
        //cout << "ADADA" << endl;
        tube2.pop();
        direcs.push_back(make_pair(2, 1));
        ans += 1;
    }
    if (tube1.empty() == false) {
        bot = tube1.top();
    } else if (tube2.empty() == false)  {
        if (tube2.top() == 1)   {
            bot = 2;
        } else  {
            bot = 1;
        }
    }
    while (tube3.empty() == false)  {
        int cur = tube3.top();
        tube3.pop();
        if (cur == bot)   {
            ans += 1;
            direcs.push_back(make_pair(3, 1));
        } else  {
            ans += 1;
            direcs.push_back(make_pair(3, 2));
        }
    }
    
    cout << ans << endl;
    if (k != 1) {
        for (auto i : direcs)   {
            cout << i.first << ' ' << i.second << endl;
        }
    }
}

int main()  {
    //freopen("testtubes.in","r",stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}