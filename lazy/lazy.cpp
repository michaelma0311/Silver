#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("lazy.in");
	ofstream cout("lazy.out");
	int n, k; cin >> n >> k;
	int ans = 0;
	int prefix[n+1][n+1], a[n+1][n+1];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	// prefix[i][j] is the ith 1d prefix sum of all elements from a[i][0] to a[i][j-1]
	// in order words, instead of creating a 2d prefix sum, just create an array of 1d prefix sums for each row.
	for(int i = 0; i < n; i++)
	{
		prefix[i][0]=0;
		for(int j = 0; j < n; j++)
			prefix[i][j+1] = prefix[i][j] + a[i][j];
	}
	// check each cell in the grid and find max value for each cell in O(N). Total time: O(N^3)
	// notice all reachable cells from (i,j) form a horizontal(or vertical) diamond, so calculate the sum of elements in a particular row of the diamond formed at (i,j)(Do this for all rows in the diamond). 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			// Use pointers left and right, which point to the leftmost and rightmost elements of the current row in the diamond and keep track of current row with l
			int sum = 0, l = i;
			int left = j-k+1, right = j+k+1;
			//prefix[l][] = prefix arr for lth row
			while(l>=0 and right>=left){ //upper part of the diamond
				sum+=prefix[l][min(n,right)]-prefix[l][max(1, left)-1]; 
				right--, left++, l--; // update pointers and current row
			}
			l=i+1, left = j-k+2, right = j+k;
			while(l<n and right>=left){ // lower part, same
				sum+=prefix[l][min(n,right)]-prefix[l][max(1, left)-1];
				right--, left++, l++; 
			}
			ans = max(ans, sum);
		}
	}
	cout << ans;
}
