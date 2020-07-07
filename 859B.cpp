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
    int n,m,ans=0;
    cin>>n;
    m=sqrt(n);
    ans=2*m;
    ans+=2*(n/m);
    n-=(m*(n/m));
    if(m>1)
        ans+=2*max((int)(bool)(n),(n/(m-1)));
    cout<<ans;
    return 0;
}
