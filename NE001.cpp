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
    int t,n,p,i,j;
    ll sum1,sum2,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum1=0;
        sum2=0;
        ans=0;
        p=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=n-1;i>=0;i--)
        {
            if(a[i]<0)
                break;
            sum1+=a[i];
            p++;
        }
        for(j=i;j>=0;j--)
            sum2+=a[j];
        ans=(sum1*(ll)p)+sum2;
        for(;i>=0;i--)
        {
            sum1+=a[i];
            sum2-=a[i];
            p++;
            ans=max(ans,(sum1*(ll)p)+sum2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
