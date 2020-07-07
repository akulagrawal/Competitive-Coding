#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int a[MAX],t[MAX],sum=0,sum1[MAX],vis[MAX],k,p=0,ans[5];
vector<int> v[MAX];

void dfs(int n)
{
    vis[n]=1;
    int x;
    sum1[n]+=t[n];
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
        {
            dfs(v[n][i]);
            sum1[n]+=sum1[v[n][i]];
        }
        else
            x=i;
    }
    if(sum1[n]==sum&&p<3)
    {
        sum1[n]=0;
        if(n!=k)
        {
            ans[p]=n;
            p++;
        }
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&t[i]);
        if(a[i])
        {
            v[i].pb(a[i]);
            v[a[i]].pb(i);
        }
        else
            k=i;
        sum+=t[i];
    }
    if(sum%3)
    {
        printf("-1");
        return 0;
    }
    sum/=3;
    dfs(k);
    if(p<2)
        printf("-1");
    else
        printf("%d %d",ans[0],ans[1]);
    return 0;
}
