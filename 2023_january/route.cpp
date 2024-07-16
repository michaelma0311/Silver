#include <bits/stdc++.h>

using namespace std;

int main()  {
    stack<long long> left;
    stack<long long> right;
    string ans = "";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        right.push(p-1);
        ans += "R";
    }
    while(right.empty() == false || left.empty() == false)   {
        
        if (right.empty() == true)  {
            //cout << "break" << endl;
            while (left.size() != 0)    {
                right.push(left.top()-1);
                left.pop();
                ans += 'R';
            }
        } else  {
            //cout << right.top() << ' ' << ans << endl;
            if (right.top() == 1)  {
                if (left.size() == 0)   {
                    right.pop();
                    ans += "L";
                } else  {
                    while (left.size() != 0)    {
                        right.push(left.top()-1);
                        left.pop();
                        ans += "R";
                    }
                    
                }
            } else  {
                int cur = right.top();
                left.push(cur-1);
                //cout << "left " << cur << endl;
                right.pop();
                ans += "L";
            }
        }
        
    }
    cout << ans << endl;
}

/*RRRRRRLRLLLLLLRRRRLLLRRRLRLRLLLRLL*/
/*RRRRRRLRLLLLLLRRRRLLLRRRLRLRLLLRLL*/