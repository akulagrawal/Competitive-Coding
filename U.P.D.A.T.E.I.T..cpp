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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,u,l,r,val,q,i;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&u);
        while(u--)
        {
            scanf("%d%d%d",&l,&r,&val);
            a[l]+=val;
            a[r+1]-=val;
        }
        for(i=1;i<n;i++)
            a[i]+=a[i-1];
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&u);
            printf("%d\n",a[u]);
        }
    }
    return 0;
}
