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

ll a[MAX],b[MAX],c[MAX],asum[MAX],csum[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,p,q,r,i,n,j,k;
    ll sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>p>>q>>r;
        for(i=0;i<p;i++)
            cin>>a[i];
        for(i=0;i<q;i++)
            cin>>b[i];
        for(i=0;i<r;i++)
            cin>>c[i];
        sort(a,a+p);
        sort(b,b+q);
        sort(c,c+r);
        for(i=0;i<p;i++)
            asum[i+1]=asum[i]+a[i];
        for(i=0;i<r;i++)
            csum[i+1]=csum[i]+c[i];
        i=q;
        j=p-1;
        k=r-1;
        while(i)
        {
            while(a[j]>b[i-1]&&j>=0)
                j--;
            while(c[k]>b[i-1]&&k>=0)
                k--;
            sum=(sum+(((asum[j+1]+(ll)(j+1)*b[i-1])%mod)*((csum[k+1]+(ll)(k+1)*b[i-1])%mod)))%mod;
            i--;
        }
        cout<<sum<<endl;
    }
    return 0;
}
