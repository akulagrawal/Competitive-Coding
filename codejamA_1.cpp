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

ll a[20];

int main()
{
    //freopen ("A-large.in","r",stdin);
    //freopen ("output1.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll n;
    string s;
    cin>>t;
    int i,j;
    for(i=1;i<=t;i++)
    {
        memset(a,0,sizeof(a));
        cin>>s;
        cout<<"Case #"<<i<<": ";
        n=0;
        ll p=1;
        for(j=s.size()-1;j>=0;j--)
        {
            n+=p*(ll)(s[j]-'0');
            p*=10;
            a[j]=n;
        }
        n=s.size();
        p/=10;
        ll q;
        int g=0;
        for(j=0;j<n;j++)
        {
            if((s[j]!='9')&&((s[j]-'0')%2==1))
            {
                if(j<n-1)
                    q=p-a[j+1];
                else
                    q=1;
                g=1;
                break;
            }
            else if((s[j]-'0')%2==1)
                break;
            p/=10;
        }
        ll k=0;
        for(j=0;j<n;j++)
        {
            if((s[j]-'0')%2)
            {
                if(j<n-1)
                    k+=a[j+1]+1;
                else
                    k++;
                break;
            }
        }
        j++;
        ll r=0;
        for(;j<n;j++)
            r=(10*r)+1;
        k+=r;
        if(g)
            k=min(k,q);
        cout<<k<<endl;
    }
    return 0;
}
