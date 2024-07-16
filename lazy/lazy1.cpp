#include <bits/stdc++.h>

using namespace std;

const int MX = 400;

int n, k;
vector<vector<int>> grid;

int main()
{
	freopen("lazy.in","r",stdin);
	freopen("lazy.out","w",stdout);

	cin >> n >> k;
	grid.resize(2*n, vector<int>(2*n));

	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int diag = i+j+1;
			// convert to a diagonal grid, 0s in between elements
			cin >> grid[diag][n-(diag-1)+2*j];
		}
	}

	for(int i=1; i<2*n; ++i){
		for(int j=1; j<2*n; ++j){
			// take prefix sums
			grid[i][j] += grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1];
		}
	}

	int f = [&](int x){ // for bounding the indices
		return max(min(x,2*n-1),1);
	};

	// problem reduces to max sum of a (2k+1)x(2k+1) subarray
	int mxSum = 0;
	for(int i=0; i<2*n; ++i){
		for(int j=0; j<2*n; ++j){
			int bi = f(i+2*k+1), bj = f(j+2*k+1), // big i, big j
				si = i, sj = j; // small i, small j
			int lr = grid[bi][bj],
				ur = grid[si][bj],
				ll = grid[bi][sj],
				ul = grid[si][sj];
			mxSum = max(mxSum, lr - ll - ur + ul);
		}
	}

	cout << mxSum << '\n';
}
