#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int d[MAX+6],a[MAX+6];

int main()
{
    int t,o1,o2,n,i,j,sum,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&o1,&o2);
        n=o1*o2;
        j=1;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&d[i]);
            a[j]+=d[i];
            if(i%o2==0)
                j+=o2;
        }
        for(i=2;i<=o2;i++)
        {
            for(j=i;j<=n;j+=o2)
            {
                if(j<=n-o2+1)
                    a[j]=a[j-1]-d[j-1]+d[j+o2-1];
                else
                    a[j]=a[j-1]-d[j-1]+d[j-n+o2-1];
            }
        }
        p=0;
        for(i=1;i<=o2;i++)
        {
            sum=0;
            for(j=i;j<=n;j+=o2)
            {
                if(a[j]>o2/2)
                    sum++;
            }
            if(sum>o1/2)
            {
                p=1;
                break;
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
