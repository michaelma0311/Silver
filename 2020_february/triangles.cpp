#include <bits/stdc++.h>

using namespace std;

int n;
const int r = 1000000007;
vector<int> x;
vector<int> y;
unordered_map<int, vector<pair<int, int>>> xto;
unordered_map<int, vector<pair<int, int>>> yto;
vector<long long> xsu;
vector<long long> ysu;

int main()  {
    //freopen("triangles.in","r",stdin);
	//freopen("triangles.out","w",stdout);
    cin >> n;
    x = vector<int>(n);
    y = vector<int>(n); 
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (xto.find(x[i]) == xto.end())    {
            xto[x[i]] = vector<pair<int, int>>();
        }   
        xto[x[i]].push_back(make_pair(y[i], i));
        if (yto.find(y[i]) == yto.end())    {
            yto[y[i]] = vector<pair<int, int>>();
        }
        yto[y[i]].push_back(make_pair(x[i], i));
    }
    xsu = vector<long long>(n);
    ysu = vector<long long>(n);
    for (int i = 0; i < n; i++) {
        xsu[i] = 0;
        ysu[i] = 0;
    }
    for (pair<int, vector<pair<int, int>>> i : xto) {
        vector<pair<int, int>> sec = i.second;
        vector<pair<int, int>> temp = sec;
        sort(temp.begin(), temp.end());
        long long su = 0;
        for (int i = 0; i < temp.size(); i++)   {
            su += temp[i].second - temp[0].second;
        }
        ysu[temp[0].first] = su;
        for (int i = 1; i < temp.size(); i++)   {
            int dist = temp[i].second - temp[i-1].second;
            su += i * dist;
            su -= (temp.size()-i) * dist;
            ysu[temp[i].first] = su;
        }
    }
    for (pair<int, vector<pair<int, int>>> i : yto) {
        vector<pair<int, int>> sec = i.second;
        vector<pair<int, int>> temp = sec;
        sort(temp.begin(), temp.end());
        long long su = 0;
        for (int i = 0; i < temp.size(); i++)   {
            su += temp[i].first - temp[0].first;
        }
        xsu[temp[0].second] = su;
        for (int i = 1; i < temp.size(); i++)   {
            int dist = temp[i].first - temp[i-1].first; 
            su += i * dist;
            su -= (temp.size() - i) * dist;
            xsu[temp[i].second] = su;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += xsu[i] * ysu[i];
        ans = ans % r;
    }
    cout << ans << endl;
    
}