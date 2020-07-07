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

double dp[1003][1003];

double func(int x,int y)
{
    if(!x||y<0)
        return 0;
    if(!y)
        return 1;
    if(dp[x][y])
        return dp[x][y];
    double k,ans;
    double w=(double)x, b=(double)y;
    ans=w/(b+w);
    k=b/(w+b);
    b--;
    if(!b)
        return dp[x][y]=ans;
    k=k*b/(w+b);
    b--;
    ans+=k*b*func(x,y-3)/(w+b);
    ans+=k*w*func(x-1,y-2)/(w+b);
    return dp[x][y]=ans;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w,b;
    cin>>w>>b;
    cout<<setprecision(10)<<fixed<<func(w,b);
    return 0;
}
