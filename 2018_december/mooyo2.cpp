#include <bits/stdc++.h>

using namespace std;

int n, k;

int board[101][101];
bool visited[101][101];
vector<pair<int, int>> lis;
bool change;
void grav() {
    for (int i = 0; i < 10; i++) {
        //cout << "Adadadada" << endl;
        int cur = n-1;
        int count = 0;
        vector<int> nums;
        for (int j = n-1; j >= 0; j--)  {
            if (board[j][i] != 0)   {
                nums.push_back(board[j][i]);
                cur -= 1;
            }
        }
        //cout << "inside " << cur << endl;
        for (int j = n-1; j > cur; j--) {
            board[j][i] = nums[count];
            count += 1;
        }
        for (int j = cur; j >= 0; j--)    {
            board[j][i] = 0;
        }
    }
}

void ff(int x, int y, int state)   {
    if (x < 0 || x >= n || y < 0 || y >= 10 || visited[x][y] || board[x][y] != state)   {
        return;
    }
    lis.push_back(make_pair(x, y));
    visited[x][y] = true;
    ff(x+1, y, state);
    ff(x-1, y, state);
    ff(x, y+1, state);
    ff(x, y-1, state);
}

int main()  {
    freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
    cin >> n >> k;
    //cout << n << endl;
    for (int i = 0; i < n; i++)    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)     {
            board[i][j] = s[j] - '0';
        }
    }
    while (true)    {
        change = false;
        for (int i = 0; i < 101; i++)   {
            for (int j = 0; j < 101; j++)   {
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++)    {
                if (visited[i][j] == false && board[i][j] != 0) {
                    lis.clear();
                    ff(i, j, board[i][j]);
                    if (lis.size() >= k)    {
                        for (auto k : lis)  {
                            board[k.first][k.second] = 0;
                            change = true;
                        }
                    }
                }
            }
        }
        if (change == false)    {
            break;
        }
        grav();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)    {
            cout << board[i][j];
        }
        cout << endl;
    }
}
