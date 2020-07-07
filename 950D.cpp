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
ll pow2[100];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    ll n;
    cin>>n>>q;
    ll i;
    pow2[0]=1;
    for(i=1;i<=60;i++)
    {
        pow2[i]=2*pow2[i-1];
    }
    for(i=0;i<q;i++)
        cin>>a[i];
    ll j=0,pos;
    for(i=0;i<q;i++)
    {
        if(a[i]%2)
            cout<<(a[i]+1)/2<<endl;
        else
        {
            ll r=((2*n-a[i])/2);
            ll pos=a[i];
            while(pos%2==0)
            {
                pos+=r;
                r=((2*n-pos)/2);
            }
            cout<<(pos+1)/2<<endl;
        }
    }
    return 0;
}
