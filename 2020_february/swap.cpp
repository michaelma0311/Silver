#include <iostream>
#include<fstream>
#include<vector>

using namespace std;



int n, m, k;
const int r = 100001;
int lis[r];
bool visited[r];

int main()  {
    freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        lis[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < (y-x+1)/2; j++) {
            swap(lis[x+j], lis[y-j]);           
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == false)    {
            visited[i] = true;
            vector<int> cyc;
            cyc.push_back(i);
            int cur = lis[i];
            int nxt;
            while (cur != i)    {
                visited[cur] = true;
                cyc.push_back(cur);
                cur = lis[cur];
            }
            nxt = k%cyc.size();
            for (int j = 0; j < cyc.size(); j++) {
                lis[cyc[j]] = cyc[(j+nxt) % cyc.size()];
            }
        }
    }
    for (int i = 1; i <= n; i++)    {
        cout << lis[i] << endl;
    }
}

























/*int main() {
    fin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int l,r;
        fin >> l >> r;
        for (int j =0; j < (r-l+1)/2; j++) {
            int temp = a[l+j];
            a[l+j] = a[r-j];
            a[r-j] = temp;
        }
    }

    for (int i = 0; i< n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int start = a[i];
            vector<int> cyc;
            cyc.push_back(i);
            while (start !=i) {
                visited[start] = true;
                cyc.push_back(start);
                start = a[start];
            }
            int mod = k % cyc.size();
            for (int j = 0; j < cyc.size(); j++) {
                a[cyc[j]] = cyc[(j+mod) % cyc.size()];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        fout << a[i] << endl;
    }
}
*/