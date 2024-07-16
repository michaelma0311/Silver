#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100001

int N,M;
int f[MAXN];
int s[MAXN];
int occ[MAXN];

int ans[MAXN];

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> f[i] >> s[i];
	int cnt = 0;
	for(int i=N-1;i>=0;i--)
	{
		int j = i;
		int pos = f[i];
		while(1)
		{
			if(occ[pos] == 0)
			{
				occ[pos] = j;
				cnt++;
				break;
			}
			else if(occ[pos] < j)
				break;
			else
			{
				int k = occ[pos];
				occ[pos] = j;
				if(pos == s[k])
					break;
				j = k;
				pos = s[k];
			}
		}
		ans[i] = cnt;
	}
	for(int i=0;i<N;i++)
		cout << ans[i] << '\n';
}