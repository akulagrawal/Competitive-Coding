#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 2000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int compute(int n)
{
    int p=0;
    while(n)
    {
        int k=n%10;
        n/=10;
        if(k%2)
            p+=k;
        else
            p-=k;
    }
    p=abs(p);
    return p;
}

ll a[MAX],b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    ll ans;
    for(i=1;i<MAX;i++)
    {
        a[i]=(ll)compute(i);
        b[i]=a[i]*(ll)(i-1);
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=b[n+1];
        ans+=(2*n)*(a[2*n]-a[n+1]);
        ans-=(b[2*n]-b[n+1]);
        cout<<ans<<endl;
    }
    return 0;
}
