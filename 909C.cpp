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

char s[MAX];
ll dp[5003][5003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,p=0;
    cin>>n;
    ll ans=0;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        if(s[i]=='s')
        {
            if(i>0&&s[i-1]=='f')
            {
                for(j=1;j<n;j++)
                    dp[i][j]=dp[i-1][j-1];
            }
            else if(i>0)
            {
                for(j=n-1;j>=0;j--)
                {
                    dp[i][j]+=dp[i][j+1]+dp[i-1][j];
                    dp[i][j]%=mod;
                }
            }
            else
                dp[0][0]=1;
        }
        else
        {
            if(i>0&&s[i-1]=='s')
            {
                for(j=n-1;j>=0;j--)
                {
                    dp[i][j]+=dp[i][j+1]+dp[i-1][j];
                    dp[i][j]%=mod;
                }
            }
            else if(i>0)
            {
                for(j=1;j<n;j++)
                    dp[i][j]=dp[i-1][j-1];
            }
            else
                dp[0][0]=1;
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    for(i=0;i<n;i++)
    {
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
