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

ll x1,x2,x3,x4,ans;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&x1,&x2,&x3,&x4);
        ans=min(abs(x1-x3),abs(x2-x4));
        ans+=abs(abs(x1-x3)-abs(x2-x4));
        printf("%lld\n",ans);
    }
    return 0;
}
