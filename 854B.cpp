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
    ll n,k,p;
    cin>>n>>k;
    if(k<n&&k>0)
        cout<<1;
    else
        cout<<0;
    cout<<" ";
    if(3*k<=n)
        cout<<2*k;
    else
        cout<<n-k;
    return 0;
}
