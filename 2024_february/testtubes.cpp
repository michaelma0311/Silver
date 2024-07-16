#include <bits/stdc++.h>

using namespace std;

void solve()    {
    long long n, m;
    cin >> n >> m;
    stack<long long> tube1;
    stack<long long> tube2;
    stack<long long> tube3;
    long long type = -1;
    string s1, s2;
    cin >> s1 >> s2;
    bool endsame = false;
    int start1;
    //cout << s1 << ' ' << s2 << endl;
    for (long long i = 0; i < n; i++) {
        long long x = s1[i]-'0';
        if (i == 0) {
            start1 = x;
        }
        //cout << x << endl;
        if (type == -1) {
            type = x;
        } else  {
            if (type != x)  {
                tube1.push(type);
                type = x;
                //cout << type << endl;
            }
        }
    }
    int start2;
    //cout << "SECOND" << endl;
    vector<pair<long long, long long>> direcs;
    tube1.push(type);
    type = -1;
    for (long long i = 0; i < n; i++) {
        long long y = s2[i]-'0';
        if (i == 0) {
            start2 = y;
        }
        //cout << y << endl;
        if (type == -1) {
            type = y;
        } else  {
            if (type != y)  {
                tube2.push(type);
                type = y;
                //cout << type << endl;
            }
        }
    }
    tube2.push(type);
    if (start1 == start2)    {
        endsame = true;
    }
    //cout << tube1.size() << ' ' << tube2.size() << ' ' << tube2.top()<< endl;
    long long ans = 0;
    bool tof1 = false;
    bool tof2 = false;
    if (tube2.size() == 1)  {
        tof2 = true;
    }
    if (tube1.size() == 1)  {
        tof1 = true;
    }
    while ((tof1 == false || tof2 == false))  {
        long long cur1 = tube1.top();
        long long cur2 = tube2.top();
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
                if (tube1.size() >= tube2.size())   {
                    ans += 1;
                    direcs.push_back(make_pair(2, 1));
                    tube2.pop();
                    //cout << tube2.top() << endl;
                    if (tube2.size() == 1)  {
                        if (endsame == true)    {
                            //cout << "ADAD" << endl;
                            ans += 1;
                            direcs.push_back(make_pair(2, 3));
                            if (tube3.empty() == true || tube3.top() != tube2.top())    {
                                tube3.push(tube2.top());
                            }
                            tube2.pop();
                            ans += 1;
                            tube1.pop();
                            direcs.push_back(make_pair(1, 2));
                            tube2.push(cur2);
                            endsame = false;
                            //cout << tube2.top() << endl;
                            tof2 = true;
                        }
                    }

                } else  {
                    ans += 1;
                    direcs.push_back(make_pair(1, 2));
                    tube1.pop();
                    if (tube1.size() == 1)  {
                        if (endsame == true)    {
                            ans += 1;
                            direcs.push_back(make_pair(1, 3));
                            if (tube3.empty() == true || tube3.top() != tube1.top())    {
                                tube3.push(tube1.top());
                            }
                            tube1.pop();
                            ans += 1;
                            direcs.push_back(make_pair(2, 1));
                            tube1.push(cur1);
                            tube2.pop();
                            endsame = false;
                        }
                        tof1 = true;
                    }
                }
            }
            
        } else  {
            if (tof1 == false && tof2 == false) {
                if (tube1.size() >= tube2.size())   {
                    ans += 1;
                    direcs.push_back(make_pair(2, 3));
                    tube2.pop();
                    if (tube3.empty() == true || cur2 != tube3.top())   {
                        tube3.push(cur2);
                    }
                } else  {
                    ans += 1;
                    direcs.push_back(make_pair(1, 3));
                    tube1.pop();
                    if (tube3.empty() == true || cur1 != tube3.top())   {
                        tube3.push(cur1);
                    }
                }
            } else if (tof2 == true)  {
                if (tube3.empty() == false) {
                    if (tube3.top() == tube2.top()) {
                        ans += 1;
                        direcs.push_back(make_pair(3, 2));
                        tube3.pop();
                    }
                } 
                ans += 1;
                direcs.push_back(make_pair(1, 3));
                tube1.pop();
                if (tube3.empty() == true || cur1 != tube3.top())   {
                    tube3.push(cur1);
                }
                
            } else if (tof1 == true)   {
                if (tube3.empty() == false) {
                    if (tube3.top() == tube1.top()) {
                        ans += 1;
                        direcs.push_back(make_pair(3, 1));
                        tube3.pop();
                    }
                }
                ans += 1;
                direcs.push_back(make_pair(2, 3));
                tube2.pop();
                if (tube3.empty() == true || cur2 != tube3.top())   {
                    tube3.push(cur2);
                }
            }
        }
        if (tube1.size() <= 1)  {
            tof1 = true;
        }
        if (tube2.size() <= 1)  {
            tof2 = true;
        }
    }
    bool ended = false;
    if (tof1 == true && tof2 == true && tube3.empty() == true)  {
        ended = true;
    }
    //cout << ans << endl;
    long long bot = 1;
    if (!ended) {
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
        while (!tube3.empty())  {
            long long cur = tube3.top();
            tube3.pop();
            if (cur == bot)   {
                ans += 1;
                direcs.push_back(make_pair(3, 1));
            } else  {
                ans += 1;
                direcs.push_back(make_pair(3, 2));
            }
        }
    }
    cout << ans << endl;
    if (m != 1) {
        for (auto i : direcs)   {
            cout << i.first << ' ' << i.second << endl;
        }
    }
}

int main()  {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        solve();
    }
}