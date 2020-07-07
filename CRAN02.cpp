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

int a[MAX];
map<ll,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i;
    ll ans,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        ans=0;
        my.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        my[0]++;
        for(i=0;i<n;i++)
        {
            sum+=(ll)a[i];
            my[sum]++;
            ans+=(ll)(my[sum]-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
