#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<pair<long long, long long>> adj;
    for (long long i = 0; i < n; ++i) {
        long long weight, num;
        cin >> weight >> num;
        adj.push_back({ weight, num });
    }

    sort(adj.begin(), adj.end(), greater<pair<long long, long long>>());

    vector<long long> weights(n), nums(n);
    deque<pair<long long, long long>> lis;
    for (long long i = 0; i < n; ++i) {
        weights[i] = adj[i].first;
        nums[i] = adj[i].second;
    }
    long long totam = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        long long cur, am;
        cur = adj[i].first;
        am = adj[i].second;
        //cout << "ADAD" << totam << endl;
        if (totam != m)    {
            if (m-totam >= am)  {
                //cout << "first " << endl;
                lis.push_back(make_pair(cur, am));
                totam += am;
                ans += am;
            } else  {
                long long p = m-totam;
                long long left = min(m, am)-p;
                totam = m;
                //cout << "ADAD " << endl;
                long long totadd = p;
                while (lis.front().first != cur && left != 0)    {
                    pair<long long, long long> curnum;
                    curnum = lis.front();
                    if (curnum.first >= cur + k)  {
                        if (left == curnum.second)  {
                            //cout << "second " << endl;
                            //cout << "ADADa " << endl;
                            lis.pop_front();
                            totadd += left;
                            left = 0;
                        } else if (left > curnum.second)    {
                            //cout << "third " << endl;
                            lis.pop_front();
                            totadd += curnum.second;
                            left -= curnum.second;
                        } else  {
                            //cout << "fourth " << endl;
                            lis.pop_front();
                            lis.push_front(make_pair(curnum.first, curnum.second-left));
                            totadd += left;
                            left = 0;
                        }
                    } else  {
                        //cout << "firfth " << endl;
                        break;
                    }

                }
                //cout << cur << ' ' << totadd << endl;
                lis.push_back(make_pair(cur, totadd));
                ans += totadd;
            } 
        } else  {
            long long left = min(am, m);
            //cout <<"ADADa " <<  left << endl;
            long long totadd = 0;
            while (lis.front().first != cur && left != 0)    {
                pair<long long, long long> curnum;
                curnum = lis.front();
                //cout << curnum.first << ' ' << curnum.second << ' ' << left << endl;
                if (curnum.first >= cur + k)  {
                    if (left == curnum.second)  {
                        //cout << "6" << endl;
                        lis.pop_front();
                        totadd += left;
                        left = 0;
                    } else if (left > curnum.second)    {
                        //cout << "7" << endl;
                        lis.pop_front();
                        totadd += curnum.second;
                        left -= curnum.second;
                    } else  {
                        //cout << "8" << endl;
                        lis.pop_front();
                        lis.push_front(make_pair(curnum.first, curnum.second-left));
                        totadd += left;
                        left = 0;
                    }
                } else  {
                    break;
                }
            }
            lis.push_back(make_pair(cur, totadd));
            ans += totadd;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}