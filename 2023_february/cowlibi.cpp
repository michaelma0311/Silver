/*#include <bits/stdc++.h>

using namespace std;
#include<cmath>
struct Event {
    long long x, y, t;
    bool isGrazing;
};

bool compareEvents(Event a, Event b) {
    return a.t < b.t;
}
vector<Event> cur;
int n, m;
bool check(long long start, long long end, long long temp, bool bs, bool be) {
    
    Event sp = cur[start];
    Event ep = cur[end];
    Event cp = cur[temp];
    bool first = (pow((cp.t-sp.t), 2) >= (pow(abs(cp.x-sp.x), 2) + pow(abs(cp.y-sp.y), 2)));
    bool sec = (pow((ep.t-cp.t), 2) >= (pow(abs(ep.x-cp.x), 2) +pow(abs(ep.y-cp.y), 2)));
    //cout << "check " << start << ' ' << end << ' ' << temp << ' ' << first << ' ' << sec << ' ' << "endorstart " << bs << ' ' << be << ' ' << cp.x << ' ' << cp.y << ' ' << cp.t  << endl;
    if (bs == true) {
        if (sec)    {
            return true;
        }
    } else if (be == true)  {
        if (first)  {
            return true;
        }
    } else  {
        if (first && sec)   {
            return true;
        }
    }
    return false;
}
int main()  {
    freopen("cowlibi.in","r",stdin);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        long long x, y, t;
        cin >> x >> y >> t;
        cur.push_back({x, y, t, true});
    }
    for (int i = 0; i < m; i++) {
        long long x, y, t;
        cin >> x >> y >> t;
        cur.push_back({x, y, t, false});
        
    }
    sort(cur.begin(), cur.end(), compareEvents);
    
    long long first = 0;
    long long end = 0;
    bool fir = false;
    long long ans = 0;
    while (end != n+m) {
        //cout << "end " << end << endl;
        struct Event p = cur[end];
        
        if (p.isGrazing == true)    {

            long long from = first;
            //cout << "inside " << first << ' ' << end << endl;
            bool yn = false;
            while (from != end+1)    {
                if (from == 0 && cur[from].isGrazing == false)  {
                    yn = true;
                }
                if (cur[from].isGrazing == true)    {
                    from += 1;
                    continue;
                }
                if (yn == true) {
                    if (check(first, end, from, true, false))   {
                        ans += 1;
                    }
                }else if (check(first, end, from, false, false))    {
                    ans += 1;
                }
                
                from += 1;
            }
            first = end;
            
        } 
        end += 1;
    }
    end -= 1;
    //cout << cur[6].t << endl;
    if (end != first)   {
        long long from = first;
        while (from != end) {
            from += 1;
            if (check(first, end, from, false, true))   {
                ans += 1;
            }
        }
    }
    long long sol = m-ans;

    cout << sol << endl;
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Grazing {
    int t, x, y;
};

bool operator<(const Grazing& a, const Grazing& b) {
    return a.t < b.t;
}

bool reachable(Grazing a, Grazing b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2) <= pow(a.t - b.t, 2);
}

int main() {
    int G, N;
    cin >> G >> N;

    vector<Grazing> grazings(G);
    for (int i = 0; i < G; i++) {
        cin >> grazings[i].t >> grazings[i].x >> grazings[i].y;
    }
    sort(grazings.begin(), grazings.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        Grazing alibi;
        cin >> alibi.t >> alibi.x >> alibi.y;

        int pos = lower_bound(grazings.begin(), grazings.end(), alibi) - grazings.begin();
        cout << pos << endl;
        bool innocent = true;
        bool touch = false;
        if (pos >= 0 && pos < G)    {
            touch = true;
            if (reachable(grazings[pos], alibi) == false)    {
                innocent = false;
            } 
        } 
        if (pos-1 >= 0 && pos-1 < G)    {
            if (reachable(grazings[pos-1], alibi) == false) {
                if (touch == false)   {
                    innocent = false;
                } else if (touch == true && innocent == true) {
                    innocent = true;
                }
            } 
        }  
        if (innocent = true)    {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}