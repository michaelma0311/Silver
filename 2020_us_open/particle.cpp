#include <iostream>
#include <algorithm>
using namespace std;
const int r = 1000001;
 
int n;
int x[r], y[r];
int lis[r];
int mi[r];
int ma[r];
 
bool cmp(int a,int b)
{
	if(x[a]==x[b]) {
        return y[a]<y[b];
    }
	return x[a]<x[b];
}
 
 
int main()
{
	freopen("moop.in","r",stdin);
	freopen("moop.out","w",stdout);
    
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x[i] >> y[i];
		lis[i] = i;
	}
	sort(lis,lis+n,cmp);

	mi[0] = y[lis[0]];
    ma[n-1] = y[lis[n-1]];
	for(int i=1;i<n;i++)    {
        //cout << 'a' << endl;
		mi[i] = min(mi[i-1], y[lis[i]]);
    }
	for (int i = n-2; i >= 0; i--)  {

        ma[i] = max(ma[i+1], y[lis[i]]);
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++)	{
		if (mi[i] >)
	}

}