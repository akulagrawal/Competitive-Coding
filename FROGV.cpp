#include<bits/stdc++.h>

using namespace std;

int n,p,a,b;
long k,temp,num[100005];
pair<long,int> ar[100005];
bool ans[100005];

int main()
{
    int i,j,t;
    scanf("%d%d%d",&n,&k,&p);
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&temp);
        ar[i]=make_pair(temp,i);
    }
    sort(ar+1,ar+n+1);
    j=n;
    for(i=n;i>1;i--)
    {
        t=ar[i].second;
        num[t]=j;
        if((ar[i].first-ar[i-1].first)>k)
            j=i-1;
    }
    t=ar[i].second;
    num[t]=j;
    for(i=0;i<p;i++)
    {
        scanf("%d%d",&a,&b);
        if(num[a]==num[b])
            ans[i]=1;
    }
    for(i=0;i<p;i++)
    {
        if(ans[i]==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
