#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    int n,m,i,j,k,l,r;
    scanf("%d%d",&n,&m);
    long a[n+5][m+5];
    int b[n+5][m+5],maxm[n+5];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=0;
        }
    }
    for(i=0;i<m;i++)
        b[0][i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]>=a[i-1][j])
                b[i][j]=b[i-1][j]+1;
        }
    }
    for(i=0;i<n;i++)
    {
        maxm[i]=b[i][0];
        for(j=1;j<m;j++)
        {
            if(maxm[i]<b[i][j])
                maxm[i]=b[i][j];
        }
    }
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&l,&r);
        if(r-l<=maxm[r-1])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
