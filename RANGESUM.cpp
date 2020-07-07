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
vector<ll> b;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,q,t,l,r;
    ll x,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=2;i<=n;i++)
        a[i]+=a[i-1];
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%d",&l,&r);
            if(l>b.size())
                ans=a[r-b.size()]-a[l-b.size()-1];
            else if(r>b.size())
                ans=b[l-1]+a[r-b.size()];
            else
            {
                if(r<b.size())
                    ans=b[l-1]-b[r];
                else
                    ans=b[l-1];
            }
            printf("%lld\n",ans);
        }
        else
        {
            scanf("%lld",&x);
            if(!b.size())
                b.insert(b.begin(),x);
            else
                b.insert(b.begin(),x+b[0]);
        }
    }
    return 0;
}
