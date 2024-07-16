#include<bits/stdc++.h>
using namespace std;


int n, k;
const int r = 200001;

int x[r],y[r]; // A B
int lis[100001]; //P
vector<int>swaps[100001]; //S
queue<int> qu;
bool visited[100001];
int from[100001]; 
int nums[100001];
int ans;

void c1(int cur)    {
    for (int i : swaps[cur])    {
        if (nums[i] == 0)   {
            ans += 1;
        }
        nums[i] += 1;
    }
}

void c2(int cur)    {
    for (int i : swaps[cur])    {
        if (nums[i] == 1)   {
            ans -= 1;
        }
        nums[i] -= 1;
    }
}

void dfs(int cur)   {
    
    visited[cur] = true;
    c1(cur);
    qu.push(cur);
    if (visited[lis[cur]] == false)   {
        dfs(lis[cur]);
    }
    
}
int main()  {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        from[i] = i;
        swaps[i].push_back(i);
    }
    for (int i=0;i<k;i++){
        swaps[from[x[i]]].push_back(y[i]);
        swaps[from[y[i]]].push_back(x[i]);
        swap(from[x[i]],from[y[i]]);
    }
    for (int i=1;i<=n;i++)  {
        lis[from[i]] = i;
    }
    int sol[100001];
    for (int i=1;i<=n;i++)  {
        if (visited[i] == false){
            dfs(i);
            int temp=ans; 
            while (!qu.empty()){
                c2(qu.front());
                sol[qu.front()]=temp;
                qu.pop();
            }
        }
    }
    for (int i=1;i<=n;i++)    {
        cout<<sol[i]<<endl;
    }
}