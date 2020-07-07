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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n,k,ans;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ans=2*n*k;
        ans-=(2*n);
        ans+=2;
        ans=ans/k;
        cout<<setprecision(10)<<fixed<<ans<<endl;
    }
    return 0;
}
