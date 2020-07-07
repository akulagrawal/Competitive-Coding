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

ll dp[103][103][20];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,c,x,y,s,i,j,t,x1,y1,x2,y2,sum,m;
    cin>>n>>q>>c;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>s;
        dp[x][y][15]+=s;
        dp[x][y][s]+=1;
    }
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            dp[i][j][15]+=dp[i-1][j][15]+dp[i][j-1][15]-dp[i-1][j-1][15];
            for(int k=0;k<=c;k++)
                dp[i][j][k]+=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
        }
    }
    while(q--)
    {
        cin>>t>>x1>>y1>>x2>>y2;
        if(x1>x2)
        {
            x=x1;
            x1=x2;
            x2=x;
        }
        if(y1>y2)
        {
            y=y1;
            y1=y2;
            y2=y;
        }
        sum=0;
        //sum=dp[x2][y2][15]-dp[x2][y1-1][15]-dp[x1-1][y2][15]+dp[x1-1][y1-1][15];
        for(int k=0;k<=c;k++)
        {
            m=dp[x2][y2][k]-dp[x2][y1-1][k]-dp[x1-1][y2][k]+dp[x1-1][y1-1][k];
            sum+=((t+k)%(c+1))*m;
            //cout<<sum<<" ";
        }
        cout<<sum<<"\n";
    }
    return 0;
}
