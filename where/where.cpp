#include <bits/stdc++.h> 
using namespace std;
const int r = 20;
int minx, maxx, miny, maxy;
vector<vector<char>> grid(r, vector<char>(r));
vector<vector<bool>> visited(r, vector<bool>(r));
struct pcl {
    int i1, j1, i2, j2;
};
void ff(int i, int j, char color)   {
    if (i < minx || i > maxx || j < miny || j > maxy || visited[i][j] == true || grid[i][j] != color)   {
        return;
    }
    visited[i][j] = true;
    ff(i+1, j, color);
    ff(i-1, j, color);
    ff(i, j+1, color);
    ff(i, j-1, color);

}
bool canpcl(int x1, int y1, int x2, int y2) {
    vector<int> colorcount(26, 0);

	minx = x1;
	maxx = x2;
	miny = y1;
	maxy = y2;

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (!visited[i][j]) {
				char curco = grid[i][j];
				colorcount[curco - 'A']++;
				ff(i, j, curco);
			}
		}
	}
    
    fill(visited.begin(), visited.end(), vector<bool>(r, false));
    int amco = 0;
    bool c1 = false;
    bool c2 = false;
    for (int i = 0; i < 26; i++)    {
        
        if (colorcount[i] != 0) {
            amco += 1;
            //cout << colorcount[i] << endl;
        }
        if (colorcount[i] == 1) {
            c1 = true;
        }
        if (colorcount[i] > 1)  {
            c2 = true;
        }
    }
    //cout << amco << ' ' << cth1 << ' ' << cmt1 << endl;
    if (amco == 2 && c1 == true && c2 == true)  {
        return true;
    }
    return false;
}
bool is_inside(pcl a, pcl b) {
	return (
		a.i1 >= b.i1 &&
		a.i2 <= b.i2 &&
		a.j1 >= b.j1 &&
		a.j2 <= b.j2
	);
}
int main()  {
    freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];  
        }
    }
    vector<pcl> lists;

    for (int x1 = 0; x1 < n; x1++)  {
        for (int y1 = 0; y1 < n; y1++)  {
            for (int x2 = 0; x2 < n; x2++)  {
                for (int y2 = 0; y2 < n; y2++)  {
                    if (canpcl(x1, y1, x2, y2)) {
                        //cout << "aa" << endl;
                        pcl temp = {x1, y1, x2, y2};
                        lists.push_back(temp);
                    }
                }
            }
        }
    }
    for (int i = 0; i < lists.size(); i++)  {
       //cout << "num" << endl;
        pcl cur = lists[i];
        //cout << cur.i1 << ' ' << cur.i2 << ' ' << cur.j1 << ' ' << cur.j2 << endl;
        bool tof = true;
        for (int j = 0; j < lists.size(); j++)  {
            if (i == j) {
                continue;
            }
            pcl ocur = lists[j];
            //cout << cur.i1 << ' ' << ocur.i1 << ' ' << cur.i2 << ' ' << ocur.i2 << endl;
            if (is_inside(cur, ocur))   {
                //cout << "awda" << endl;
                tof = false;
                break;
            }
        }
        ans += tof;

    }
    cout << ans << endl;
}