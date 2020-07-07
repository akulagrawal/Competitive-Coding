#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

ll x[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    int n,i,ans=0;
    cin>>a>>b>>c;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>x[i];
    for(i=0;i<n;i++)
    {
        if(x[i]>b&&x[i]<c)
            ans++;
    }
    cout<<ans;
    return 0;
}
