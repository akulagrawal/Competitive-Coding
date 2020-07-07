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

int cost[102],fun[102],sum;

int KnapSack(int n,int w)
{
    int i,j;
    int wt[n+1][w+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0||j==0)
                wt[i][j]=0;
            else if(cost[i-1]<=j)
                wt[i][j]=max(fun[i-1]+wt[i-1][j-cost[i-1]],wt[i-1][j]);
            else
                wt[i][j]=wt[i-1][j];
        }
    }
    sum=w;
    for(j=w;j>=0;j--)
        if(wt[n][j]!=wt[n][w])
        {
            sum=j;
            break;
        }
    return wt[n][w];
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p,i,j;
    while(1)
    {
        scanf("%d%d",&p,&n);
        if(!n&&!p)
            break;
        for(i=0;i<n;i++)
            scanf("%d%d",&cost[i],&fun[i]);
        printf("%d %d\n",sum+1,KnapSack(n,p));
    }
    return 0;
}
