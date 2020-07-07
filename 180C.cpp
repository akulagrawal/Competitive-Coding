#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int dp[5][5];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n,i;
    cin>>s;
    n=s.size();
    if(s[0]>='a')
    {
        dp[0][0]=0;
        dp[0][1]=1;
    }
    else
    {
        dp[0][0]=1;
        dp[0][1]=0;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]>='a')
        {
            dp[i%2][0]=min(dp[!(i%2)][0],dp[!(i%2)][1]);
            dp[i%2][1]=dp[!(i%2)][1]+1;
        }
        else
        {
            dp[i%2][0]=min(dp[!(i%2)][0],dp[!(i%2)][1])+1;
            dp[i%2][1]=dp[!(i%2)][1];
        }
    }
    cout<<min(dp[!(n%2)][0],dp[!(n%2)][1]);
    return 0;
}
