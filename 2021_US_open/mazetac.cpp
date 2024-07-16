#include<bits/stdc++.h>
using namespace std;

int n;
char board[25][25][3];
bool visited[25][25][19683];
int pow3[10];

set<int> ans;

bool didWin(int b) {
    int tttBoard[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tttBoard[i][j] = b % 3;
            b /= 3;
        }
    }
    for (int row = 0; row < 3; row++) {
        if (tttBoard[row][0] == 1 && tttBoard[row][1] == 2 && tttBoard[row][2] == 2) {
            return true;
        }
        if (tttBoard[row][0] == 2 && tttBoard[row][1] == 2 && tttBoard[row][2] == 1) {
            return true;
        }
    }
    for (int col = 0; col < 3; col++) {
        if (tttBoard[0][col] == 1 && tttBoard[1][col] == 2 && tttBoard[2][col] == 2) {
            return true;
        }
        if (tttBoard[0][col] == 2 && tttBoard[1][col] == 2 && tttBoard[2][col] == 1) {
            return true;
        }
    }
    if (tttBoard[0][0] == 1 && tttBoard[1][1] == 2 && tttBoard[2][2] == 2) {
        return true;
    }
    if (tttBoard[0][0] == 2 && tttBoard[1][1] == 2 && tttBoard[2][2] == 1) {
        return true;
    }
    if (tttBoard[0][2] == 1 && tttBoard[1][1] == 2 && tttBoard[2][0] == 2) {
        return true;
    }
    if (tttBoard[0][2] == 2 && tttBoard[1][1] == 2 && tttBoard[2][0] == 1) {
        return true;
    }
    return false;
}

void dfs(int x, int y, int num) {
    //cout << x << ' ' << y << endl;
    if (visited[x][y][num]) {
        return;
    }
    visited[x][y][num] = true;
    if (board[x][y][0] == 'M' || board[x][y][0] == 'O') {
        
        int r = board[x][y][1] - '1';
        int c = board[x][y][2] - '1';
        int ind = r*3+c;
        int cur = (num/pow3[ind])%3;  
        if (cur == 0)   {
            int ne;
            if (board[x][y][0] == 'M')  {
                ne = 1;
            } else  {
                ne = 2;
            }
            num = (num % pow3[ind]) + ne * pow3[ind] + (num - num % pow3[ind + 1]);
            if (!visited[x][y][num] && didWin(num)) {
                ans.insert(num);
                return;
            }
            visited[x][y][num] = true;
        }
    }   
    if (board[x-1][y][0] != '#') {
        dfs(x-1, y, num);
    }
    if (board[x+1][y][0] != '#') {
        dfs(x+1, y, num);
    }
    if (board[x][y-1][0] != '#') {
        dfs(x, y-1, num);
    }
    if (board[x][y+1][0] != '#')    {
        dfs(x, y+1, num);
    }
}

int main()  {
    int x = 0;
    int y = 0;
    pow3[0] = 1;
    for (int i = 1; i < 10; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j][0] >> board[i][j][1] >> board[i][j][2];
            //cout << i << ' ' << j << endl;
            if (board[i][j][0] == 'B')  {
                x = i;
                y = j;
            }

        }
    }
    dfs(x, y, 0);
    cout << ans.size() << endl;
}