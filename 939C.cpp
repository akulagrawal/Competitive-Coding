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

ll a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    int s,f;
    cin>>s>>f;
    int x=f-s;
    ll maxm=0,sum=0;
    int t=1;
    for(i=0;i<x;i++)
        sum+=a[i];
    maxm=sum;
    for(i=x;i<2*n;i++)
    {
        sum+=a[i]-a[i-x];
        if(sum>maxm)
        {
            maxm=sum;
            t=(s+2*n-(i-x+1))%n;
        }
        else if(sum==maxm)
            t=min(t,(s+2*n-(i-x+1))%n);
    }
    if(!t)
        t=n;
    cout<<t;
    return 0;
}
