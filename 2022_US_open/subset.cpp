#include <bits/stdc++.h>
using namespace std;

int main()  {
    bool doub[20][20];
    string s, t;
    cin >> s >> t;
    for (char i = 'a'; i <= 'r'; i++)   {
        int c1 = 0, c2 = 0;
        for (int j = 0; j < s.size(); j++)  {
            if (s[j] == i)  {
                c1 += 1;
            }
        }
        for (int j = 0; j < t.size(); j++)  {
            if (t[j] == i)  {
                c2 += 1;
            }
        }
        if (c1 == c2)   {
            doub[i-'a'][i-'a'] = true;
        } else  {
            doub[i-'a'][i-'a'] = false;
        }
    }
    for (char i = 'a'; i <= 'r'; i++)   {
        for (char j = i+1; j <= 'r'; j++)   {
            string temp1, temp2;
            for (int k = 0; k < s.size(); k++)  {
                if (s[k] == i || s[k] == j) {
                    temp1 += s[k];
                }
            }
            for (int k = 0; k < t.size(); k++)  {
                if (t[k] == i || t[k] == j) {
                    temp2 += t[k];
                }
            }
            if (temp1 == temp2) {
                doub[i-'a'][j-'a'] = true;
            } else  {
                doub[i-'a'][j-'a'] = false;
            }
        }
    }
    int num;
    cin >> num;
    for (int h = 0; h < num; h++)   {
        bool ans = true;
        string cur;
        cin >> cur;
        for (int i = 0; i < cur.size(); i++)    {
            if (doub[cur[i]-'a'][cur[i]-'a'] == false)    {
                ans = false;
                break;
            }
        } 
        for (int i = 0; i < cur.size(); i++)    {
            for (int j = i+1; j < cur.size(); j++)  {
                if (doub[cur[i]-'a'][cur[j]-'a'] == false)  {
                    ans = false;
                    break;
                }
            }
        }
        if (ans == false)   {
            cout << 'N';
        } else  {
            cout << 'Y';
        }
    }
}