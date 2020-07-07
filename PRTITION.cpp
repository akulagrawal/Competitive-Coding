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

bool b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll x,n;
        memset(b,0,sizeof(b));
        cin>>x>>n;
        ll sum=(n*(n+1))/2;
        sum-=x;
        if(sum%2)
        {
            cout<<"impossible\n";
            continue;
        }
        sum/=2;
        ll k=sum;
        ll i=n;
        while(sum>=i&&i>0)
        {
            if(i==x)
            {
                i--;
                continue;
            }
            sum-=i;
            b[i]=1;
            i--;
        }
        if(x==sum&&sum==1)
        {
            b[i]=1;
            b[i+1]=0;
            b[2]=1;
        }
        else if(x==sum&&sum==2)
        {
            b[i]=1;
            b[i+1]=0;
            b[3]=1;
        }
        else if(x==sum)
        {
            b[sum-1]=1;
            b[1]=1;
        }
        else
            b[sum]=1;
        ll p=0;
        for(i=1;i<=n;i++)
        {
            if(i!=x&&b[i]==1)
                p+=i;
        }
        if(p!=k)
            cout<<"impossible\n";
        else
        {
            for(i=1;i<=n;i++)
            {
                if(i==x)
                    cout<<2;
                else
                    cout<<b[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
