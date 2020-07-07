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

int a[200][200];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,k,i,p1,p2,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        p2=0;
        for(i=0;i<n;i++)
        {
            p1=0;
            for(j=0;j<m;j++)
                p1+=a[i][j];
            p2=max(p2,p1);
        }
        for(j=0;j<m;j++)
        {
            p1=0;
            for(i=0;i<n;i++)
                p1+=a[i][j];
            p2=max(p2,p1);
        }
        if(p2>k)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
