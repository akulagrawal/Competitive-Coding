#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 200005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int v1[10004],v2[10004];
int sum1[10004],sum2[10004];
pii t[10004];

int main()
{
    int n,m,i,j,p,sum;
    while(1)
    {
        sum=0;
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&v1[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&v2[i]);
        i=0;
        j=0;
        p=0;
        while(i<n&&j<m)
        {
            if(v1[i]==v2[j])
            {
                sum+=v1[i];
                t[p]=mp(i,j);
                p++;
                i++;
                j++;
            }
            else if(v1[i]<v2[j])
                i++;
            else
                j++;
        }
        i=0;
        j=0;
        while(i<n)
        {
            if(j<p&&i==t[j].f)
            {
                j++;
                i++;
                continue;
            }
            sum1[j]+=v1[i];
            i++;
        }
        i=0;
        j=0;
        while(i<m)
        {
            if(j<p&&i==t[j].s)
            {
                j++;
                i++;
                continue;
            }
            sum2[j]+=v2[i];
            i++;
        }
        for(i=0;i<=p;i++)
        {
            sum+=max(sum1[i],sum2[i]);
            sum1[i]=0;
            sum2[i]=0;
        }
        printf("%d\n",sum);
    }
    return 0;
}
