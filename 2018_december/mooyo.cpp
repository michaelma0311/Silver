#include <bits/stdc++.h>

using namespace std;

int n, k;

int board[101][101];
bool visited[101][101];
vector<pair<int, int>> lis;
int change = 0;
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

void ff(int x, int y, int temp)   {
    //cout << "inside" << x << ' '  << y << endl;
    if (x < 0 || x >= n || y < 0 || y >= 10 || board[x][y] != temp || visited[x][y] == true) {
        return;
    }
    visited[x][y] = true;
    lis.push_back(make_pair(x, y));
    ff(x-1, y, temp);
    ff(x+1, y, temp);
    ff(x, y-1, temp);
    ff(x, y+1, temp);
    
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
        change = 0;
        for (int i = 0; i < 101; i++)   {
            for (int j = 0; j < 101; j++)   {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++)    {
                //cout << "adada " << board[i][j] << endl;
                if (board[i][j] != 0 && visited[i][j] == false) {
                    lis.clear();
                    ff(i, j, board[i][j]);
                    if (lis.size() >= k)    {
                        for (int k = 0; k < lis.size(); k++)    {
                            board[lis[k].first][lis[k].second] = 0;
                            change += 1;
                        }
                    }
                }
            }
        }
        grav();
        if (change == 0)    {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)    {
            cout << board[i][j];
        }
        cout << endl;
    }
}
