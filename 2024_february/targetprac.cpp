#include <bits/stdc++.h>

using namespace std;
long long m;
bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return a.second > b.second;
}
bool cmp2(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return a.second - m * a.first > b.second - m * b.first;
}
bool cmp3(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return a.second - m * a.first < b.second - m * b.first;
}
void solve()    {
    long long n, x1;
    cin >> n >> x1;
    vector<long long> slopes(4*n);
    vector<pair<long long, long long>> onlyneg;
    vector<pair<long long, long long>> onlypos;
    vector<pair<long long, long long>> norm;
    for (long long i = 0; i < n; i++) {
        long long y1, y2, x2;
        cin >> y1 >> y2 >> x2;
        onlyneg.push_back(make_pair(x2, y2));
        onlypos.push_back(make_pair(x2, y1));
        norm.push_back(make_pair(x1, y1));
        norm.push_back(make_pair(x1, y2));
    }
    vector<long long> pos;
    vector<long long> neg;
    for (long long i = 0; i < 4*n; i++)   {
        cin >> slopes[i];
        //cout << "here " << slopes[i] << endl;
        if (slopes[i] > 0)  {
            pos.push_back(slopes[i]);
        } else  {
            //cout << "ADAD" << slopes[i] << endl;
            neg.push_back(slopes[i]);
        }
    }
    long long negsize = onlyneg.size();
    long long possize = onlypos.size();
    if (negsize > neg.size() || possize > pos.size())   {
        cout << -1 << endl;
        return;
    }
    sort(norm.begin(), norm.end(), cmp);
    for (long long i = 0; i < norm.size(); i++)   {
        if (possize == pos.size())  {
            onlyneg.push_back(norm[i]);
        } else  {
            possize += 1;
            onlypos.push_back(norm[i]);
        }
    }
    long long loans = LLONG_MAX;
    long long hians = 0;

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    //cout << neg.size() << endl;
    /*for (auto i : onlyneg)  {
        cout << "onlyneg " << i.first << ' ' << i.second << endl;
    } 
    */
    for (long long i = 0; i < neg.size(); i++)    {
        m = neg[i];
        sort(onlyneg.begin(), onlyneg.end(), cmp2);
        /*for (auto i : onlyneg)  {
            cout << "insde " << i.first << ' ' << i.second << endl;
        }
        */
        pair<long long, long long> cur = onlyneg.back();
        
        //cout << m << ' ' << cur.second-(m*cur.first) << ' ' << cur.first << ' ' << cur.second << endl;
        loans = min(loans, cur.second-(m*cur.first));
        hians = max(hians, cur.second-(m*cur.first));
        onlyneg.pop_back();
    }
    for (long long i = pos.size()-1; i >= 0; i--)    {
        m = pos[i];
        sort(onlypos.begin(), onlypos.end(), cmp3);
        pair<long long, long long> temp = onlypos.back();
        onlypos.pop_back();
        loans = min(loans, temp.second-(m*temp.first));
        hians = max(hians, temp.second-(m*temp.first));
    }
    //cout << loans << ' ' << hians << endl;
    cout << hians - loans << endl;

    
}

int main()  {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        solve();
    }
}