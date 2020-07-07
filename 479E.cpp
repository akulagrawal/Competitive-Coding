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

ll dp1[5][5005],dp2[5][5005];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b,k,i,j,t1,t2;
    ll sum=0;
    cin>>n>>a>>b>>k;
    if(a>b)
    {
        t1=n-a+1;
        t2=n-b+1;
        a=t1;
        b=t2;
    }
    dp1[0][a]=1;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=b;j++)
            dp2[!(i%2)][j]=(dp1[!(i%2)][j]+dp2[!(i%2)][j-1])%mod;
        for(j=1;j<b;j++)
            dp1[i%2][j]=(dp2[!(i%2)][(j+b-1)/2]-dp1[!(i%2)][j]+mod)%mod;
    }
    for(i=1;i<b;i++)
        sum=(sum+dp1[k%2][i])%mod;
    cout<<sum;
    return 0;
}
