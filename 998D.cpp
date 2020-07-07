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
    
    ll n;
    cin>>n;
    ll ans=(((n+3)*(n+2)*(n+1))/6);
    if(n>=6)
    {
    	ll x=((n-3)*(n-4)*(n-5))/3;
    	ans-=x;
    }
    if(n>=12)
    {
    	ll x=((n-9)*(n-10)*(n-11))/6;
    	ans+=x;
    }
    cout<<ans;


    return 0;
}