/*
ID: michael504
LANG: C++
TASK: sprime
*/
#include <bits/stdc++.h>

using namespace std;
FILE *fout;

vector<int> q;
int n;
int isprime(int n)
{
	int i;

	if(n == 2)
		return 1;

	if(n%2 == 0)
		return 0;

	for(i=3; i*i <= n; i+=2)
		if(n%i == 0)
			return 0;

	return 1;
}
void gen(int cur, int l)    {
    if (isprime(cur) == 1)  {
        if (l == n) {
            q.push_back(cur);
        } else  {
            gen(cur*10+1, l+1);
            gen(cur*10+3, l+1);
            gen(cur*10+7, l+1);
            gen(cur*10+9, l+1);
        }
        
    }
}

int main()  {
    FILE *fin;
    fin = fopen("sprime.in", "r");
	assert(fin != NULL);
	fout = fopen("sprime.out", "w");
	assert(fout != NULL);
    fscanf(fin, "%d", &n);
    gen(2, 1);
    gen(3, 1);
    gen(5, 1);
    gen(7, 1);
    for (int i : q) {
        cout << fprintf(fout, "%d\n", i) << endl;
    }
}