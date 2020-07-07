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

ll a[MAX],b[MAX],c[MAX],d[MAX];
pair<ll,ll> my[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    ll minm,ans,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        minm=mod;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            minm=min(minm,b[i]);
        }
        for(i=0;i<n;i++)
        {
            a[i]=a[i]%b[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[i]>=b[i])
            {
                a[i]=0;
                ans+=b[i]-a[i];
            }
            my[i]=mp(a[i],b[i]);
        }
        sort(my,my+n);
        c[0]=my[0].f;
        for(i=1;i<n;i++)
            c[i]=c[i-1]+my[i].f;
        d[0]=my[0].s;
        for(i=1;i<n;i++)
            d[i]=d[i-1]+my[i].s;
        x=my[0].f;
        y=0;
        ll z1,z2;
        for(i=1;i<n;i++)
        {
            z1=d[i-1]-c[i-1]+(ll)(i-1)*my[i].f;
            z2=y+x-my[i].f;
            if(z1<z2)
            {
                y=z1;
                x=my[i].f;
            }
            else
                y=z2;
        }
        cout<<y<<endl;
    }
    return 0;
}
