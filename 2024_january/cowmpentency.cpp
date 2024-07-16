#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.first < b.first);
}
bool cmp2(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}
struct typ{
    int st;
    int en;
    int maxn;
    
};
struct Compare {
    bool operator()(const typ& a, const typ& b) const {
        return a.en < b.en; 
    }
};
void solve()	{
	int n, q, c;
	cin >> n >> q >> c;
    vector<int> lis(n);
    vector<int> maxnum(n);
    vector<int> tempo(n);
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
        maxnum[i] = l;
        tempo[i] = lis[i];
        l = max(l, lis[i]);
    }
    vector<pair<int, int>> se(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        se[i] = make_pair(x, y);
    }
    sort(se.begin(), se.end(), cmp);
    priority_queue<typ, vector<typ>, Compare> que;
    int ind = 0;
    bool tof = true;
    multiset<int> numsinq;
    for (int i = 0; i < n; i++) {
        //cout << i << ' ' << maxnum[i] << endl;
        if (que.empty() == true)    {
            if (lis[i] == 0)    {
                lis[i] = 1;
                maxnum[i] = max(maxnum[i], lis[i]);
            }
        } else  {
            typ cur = que.top();
            if (cur.en == i)   {
                //cout << i << endl;
                int man = 0;
                while (que.empty() == false && que.top().en == i) {
                    typ tem = que.top();
                    que.pop();
                    numsinq.erase(find(numsinq.begin(), numsinq.end(), tem.maxn));
                    man = max(man, max(maxnum[i], tem.maxn));
                }
                if (lis[i] == 0)    {
                    lis[i] = man+1;
                    maxnum[i] = max(maxnum[i], lis[i]);
                } else  {
                    if (lis[i] < man+1)  {
                        //cout << "ADADd" << endl;
                        tof = false;
                        break;
                    }
                }
            }
            if (que.empty() == false)   {
                int mic = *numsinq.end();
                if (lis[i] > mic)   {
                    //cout << mic << ' ' << "ADAD " << lis[i] << endl; 
                    tof = false;
                    break;
                }
                if (tempo[i] == 0)    {
                    lis[i] = max(lis[i], 1);
                    maxnum[i] = max(maxnum[i], lis[i]);
                }
            }
        }
        if (ind < q)    {
            if (se[ind].first == i)   {
                typ curr;
                curr.st = se[ind].first;
                curr.en = se[ind].second;
                curr.maxn = maxnum[i];
                que.push(curr);
                numsinq.insert(curr.maxn);
                ind += 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (lis[i] == 0)    {
            lis[i] = 1;
        }
        if (lis[i] > c) {
            //cout << "ADAD" << endl;
            tof = false;
        }
    }
    if (tof == false)   {
        cout << -1 << endl;
        return;
    } 
    if (tof)    {
        for (int i = 0; i < n-1; i++)   {
            cout << lis[i] << ' ';
        }
        cout << lis[n-1] << endl;
    } 
	
}

int main() {
	int t;
	cin >> t;
	for (int _ = 0; _ < t; _++)	{
		solve();
	}
}