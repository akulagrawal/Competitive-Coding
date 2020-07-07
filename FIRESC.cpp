#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<int> v[100005];
bool vis[100005];
int p;
long long frnd[100005];

void dfs(int n)
{
    frnd[p]++;
    vis[n]=1;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i]);
    }
}

int main()
{
    int t,n,m,i,j;
    long long prod;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        prod=1;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&i,&j);
            v[i].push_back(j);
            v[j].push_back(i);
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                p++;
            }
        }
        for(i=0;i<p;i++)
        {
            prod=(prod*frnd[i])%MOD;
            frnd[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
            v[i].clear();
        }
        printf("%d %d\n",p,prod);
    }
    return 0;
}
