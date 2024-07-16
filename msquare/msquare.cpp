/*
ID: michael504
LANG: C++
TASK: msquare
*/
#include <bits/stdc++.h>

using namespace std;

string sp (char x)  {
    return string(1, x);
}

int main()  {
    freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
    string goal;
    for (int i = 0; i < 8;i++)  {
        char x;
        cin >> x;
        goal += x;
    }
    queue<string> qu;
    map<string, string> count;
    set<string> visited;
    qu.push("12345678");
    count.insert({"12345678", ""});
    while (qu.empty() == false) {
        string cur = qu.front();
        qu.pop();
        //cout << cur << endl;
        if (cur == goal)    {
            break;
        }
        string temp = cur;
        reverse(temp.begin(), temp.end());
        //cout << temp << endl;
        if (visited.find(temp) == visited.end())   {
            visited.insert(temp);
            count.insert({temp, count[cur]+"A"});
            qu.push(temp);
        }
        string temp1 = sp(cur[3]) + sp(cur[0]) + sp(cur[1]) + sp(cur[2]) + sp(cur[5]) + sp(cur[6]) + sp(cur[7]) + sp(cur[4]) ;
        if (visited.find(temp1) == visited.end())   {
            visited.insert(temp1);
            count.insert({temp1, count[cur]+"B"});
            qu.push(temp1);
        }
        string temp2 = sp(cur[0]) + sp(cur[6]) + sp(cur[1]) + sp(cur[3]) + sp(cur[4]) + sp(cur[2]) + sp(cur[5]) + sp(cur[7]);
        if (visited.find(temp2) == visited.end())   {
            visited.insert(temp2);
            count.insert({temp2, count[cur]+"C"});
            qu.push(temp2);
        }
    }
    cout << count[goal].size() << endl;
    if (count[goal].size() != 0)    {

    
        int ad = 0;
        for (char i : count[goal])  {
            cout << i;
            ad += 1;
            if (ad == 60)   {
                ad = 0;
                cout << endl;
            }
        }
        if (ad != 0)    {
            cout << endl;
        }
        //cout << count[goal] << endl;
    } else  {
        cout << endl;
    }
}