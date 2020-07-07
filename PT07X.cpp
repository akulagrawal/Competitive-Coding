#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

vector<int> v[MAX];
int sum,vis[MAX];

int dfs(int n)
{
    vis[n]=1;
    int i,p=1;
    if(!v[n].size())
        return 0;
    for(i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            p=p&dfs(v[n][i]);
    }
    sum+=!p;
    return !p;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,i,x,y;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    printf("%d\n",sum);
    return 0;
}
