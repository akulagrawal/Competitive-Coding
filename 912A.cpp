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
    ll a,b;
    cin>>a>>b;
    ll x,y,z;
    cin>>x>>y>>z;
    ll q,w,e;
    q=3*z+y;
    e=2*x+y;
    w=0;
    if(q>b)
        w+=q-b;
    if(e>a)
        w+=e-a;
    cout<<w;
    return 0;
}
