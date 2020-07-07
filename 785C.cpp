#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ll n,m,a;
    cin>>n>>m;
    if(m>=n)
    {
        cout<<n;
        return 0;
    }
    a=sqrt(1+(8*(n-m)))/2;
    if(a*(a+1)/2<n-m)
        a++;
    a+=m;
    cout<<a;
    return 0;
}
