#include <bits/stdc++.h>

using namespace std;
int n, m;
set<int> targets;
string s;
vector<int> tarhit;
vector<int> ind;
vector<set<int>> visited;
int solve(int start, int dir, set<int> tempalrhit)   {
    //cout << "iunsdie " << ' ' << start << endl;
    set<int> alrhit = tempalrhit;
    int tempans = 0;
    for (int j = start+1; j < m; j++)   {
        int curnum = ind[j] + dir;
        if (s[j] == 'F')    {
            //cout << curnum << endl;
            if (alrhit.find(curnum) != alrhit.end())    {
                continue;
            }
            if (targets.find(curnum) != targets.end())  {
                alrhit.insert(curnum);
                tempans += 1;
            }
        }
    }
    //cout << tempans << ' ' << start << ' ' << dir << endl;
    return tempans;
}
int main()  {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        targets.insert(x);
    }
    cin >> s;
    tarhit.resize(m+1);
    ind.resize(m);
    visited.resize(m+1);
    set<int> visit;
    int cur = 0;
    for (int i = 1; i < m+1; i++)   {
        if (s[i-1] == 'L')  {
            cur -= 1;
            tarhit[i] = tarhit[i-1];
        } else if (s[i-1] == 'R')   {
            cur += 1;
            tarhit[i] = tarhit[i-1];
        } else  {
            if (targets.find(cur) != targets.end()) {
                if (visit.find(cur) == visit.end())   {
                    tarhit[i] = tarhit[i-1] + 1;
                    visit.insert(cur);
                } else  {
                    tarhit[i] = tarhit[i-1];
                }
            } else  {
                tarhit[i] = tarhit[i-1];
            }
        }
        visited[i] = visit;
        ind[i-1] = cur;
    }
    int ans = 0;
    int dir = 0;
    int curhit;
    /*for (int i = 1; i < m+1; i++) {
        cout << tarhit[i] << endl;
    }
    */
    //cout << "ADAD" << endl;
    set<int> curvis;
    for (int i = 0; i < m; i++) {
        curvis = visited[i];
        curhit = tarhit[i];
        if (s[i] == 'L')    {
            ans = max(ans, solve(i, 2, curvis) + curhit);
            if (targets.find(ind[i]+1) != targets.end())  {
                if (curvis.find(ind[i]+1) == curvis.end())  {
                    set<int> tempvis = curvis;
                    tempvis.insert(ind[i]+1);
                    ans = max(ans, solve(i, 1, tempvis) + curhit + 1);
                } else  {
                    ans = max(ans, solve(i, 1, curvis) + curhit);
                }
            } else  {
                ans = max(ans, solve(i, 1, curvis) + curhit);
            }
        } else if (s[i] == 'R') {
            ans = max(ans, solve(i, -2, curvis) + curhit);
            if (targets.find(ind[i]-1) != targets.end())  {
                if (curvis.find(ind[i]-1) == curvis.end())  {
                    set<int> tempvis = curvis;
                    tempvis.insert(ind[i]-1);
                    ans = max(ans, solve(i, -1, tempvis) + curhit + 1);
                } else  {
                    ans = max(ans, solve(i, -1, curvis) + curhit);
                }
            } else  {
                ans = max(ans, solve(i, -1, curvis) + curhit);
            }
        } else  {
            ans = max(ans, solve(i, 1, curvis) + curhit);
            ans = max(ans, solve(i, -1, curvis) + curhit);
        }
    }
    cout << max(ans, tarhit.back()) << endl;
}