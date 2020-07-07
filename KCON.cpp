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

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        ll maxm1=a[0],sum=a[0],maxm2=a[n-1];
        for(i=1;i<n;i++)
        {
            sum+=a[i];
            maxm1=max(maxm1,sum);
        }
        sum=a[n-1];
        for(i=n-2;i>=0;i--)
        {
            sum+=a[i];
            maxm2=max(maxm2,sum);
        }
        ll x,y;
        if(k==1)
            x=max(maxm1,maxm2);
        else if(sum>0)
            x=maxm1+maxm2+(k-2)*sum;
        else
            x=maxm1+maxm2;
        maxm1=a[0];
        sum=a[0];
        for(i=1;i<n;i++)
        {
            sum+=a[i];
            maxm1=max(sum,maxm1);
            if(sum<0)
                sum=0;
        }
        cout<<max(maxm1,x)<<endl;
    }
    return 0;
}
