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

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = (ll)a;
    while(power>0)
    {
        if(power&1)
            result = result*value;
        value = value*value;
        power /= 2;
    }
    return result;
}

int a[55][55], col[55], row[55];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j;
    cin>>n>>m;
    ll p,q;
    ll ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>a[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    }
    ans=(ll)n*(ll)m;
    for(i=0;i<n;i++)
    {
        p=fast_pow(2,row[i]);
        ans+=p-1-row[i];
        p=fast_pow(2,m-row[i]);
        ans+=p-1-m+row[i];
    }
    for(i=0;i<m;i++)
    {
        q=fast_pow(2,col[i]);
        ans+=q-1-col[i];
        q=fast_pow(2,n-col[i]);
        ans+=q-1-n+col[i];
    }
    cout<<ans;
    return 0;
}
