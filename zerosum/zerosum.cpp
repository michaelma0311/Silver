/*
ID: michael504
LANG: C++
TASK: zerosum
*/

#include <bits/stdc++.h>

using namespace std;


int n;
vector<string> ans;

bool check(string cur)  {
    int temp = 0;
    int curn = 0;
    int sign = 1;
    for (char i : cur)  {
        if (i == '+')   {
            temp += curn*sign;
            sign = 1;
            curn = 0;
        } else if (i == '-')    {
            temp += curn*sign;
            sign = -1;
            curn = 0;
        } else if (i == ' ')    {
            curn *= 10;
        } else  {
            curn += i-'0';
        }
    }
    temp += sign*curn;
    if (temp == 0)  {
        return true;
    }
    return false;

}

void dfs(string s, int cnt)  {
    if (cnt == n)   {
        if (check(s) == true)   {
            ans.push_back(s);
        }
        return;
    }
    dfs(s+' '+to_string(cnt+1), cnt+1);
    dfs(s+'+'+to_string(cnt+1), cnt+1);
    dfs(s+'-'+to_string(cnt+1), cnt+1);

}

int main()  {
    freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);

    cin >> n;
    dfs("1", 1);
    for (auto i : ans)  {
        cout << i << endl;
    }
}