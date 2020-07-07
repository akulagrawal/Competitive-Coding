#include<bits/stdc++.h>

using namespace std;

int n,m,k,c[200005],l[200005],r[200005],vis[200005],sum1,sum2,maxm;
vector<int> v[200005];
map<int,int> my;

void dfs(int p)
{
    vis[p]=1;
    sum1++;
    my[c[p-1]]++;
    if(maxm<my[c[p-1]])
        maxm=my[c[p-1]];
    for(int i=0;i<v[p].size();i++)
    {
        if(!vis[v[p][i]])
            dfs(v[p][i]);
    }
}

int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        v[l[i]].push_back(r[i]);
        v[r[i]].push_back(l[i]);
    }
    for(i=0;i<m;i++)
    {
        if(!vis[l[i]])
        {
            dfs(l[i]);
            sum2+=sum1-maxm;
            sum1=0;
            maxm=0;
            my.clear();
        }
    }
    printf("%d",sum2);
    return 0;
}
