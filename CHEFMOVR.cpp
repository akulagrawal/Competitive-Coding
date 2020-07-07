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
pair<ll,ll> b[MAX];
pair<ll,ll> c[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,d,i,j,k1,k2;
    ll sum,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&n,&d);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<min(d,n);i++)
        {
            sum=0;
            k1=0;
            k2=0;
            b[0]=mp(0,0);
            c[0]=mp(0,0);
            for(j=i;j<n;j+=d)
                sum+=a[j];
            j/=d;
            sum=sum/j;
            for(j=i;j<n;j+=d)
            {
                if(a[j]>sum)
                {
                    b[k1]=mp(a[j]-sum,j);
                    k1++;
                }
                else if(a[j]<sum)
                {
                    c[k2]=mp(sum-a[j],j);
                    k2++;
                }
            }
            while(k1>=0&&k2>=0)
            {
                if(b[k1].f>c[k2].f)
                {
                    b[k1].f-=c[k2].f;
                    ans+=abs(b[k1].s-c[k2].s)*c[k2].f;
                    c[k2].f=0;
                    k2--;
                }
                else
                {
                    c[k2].f-=b[k1].f;
                    ans+=abs(b[k1].s-c[k2].s)*b[k1].f;
                    b[k1].f=0;
                    k1--;
                }
            }
            if(b[0].f||c[0].f)
            {
                ans=-1;
                break;
            }
        }
        if(ans>0)
            ans/=d;
        printf("%lld\n",ans);
    }
    return 0;
}
