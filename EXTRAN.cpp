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

long a[MAX];

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        sort(a,a+n);
        for(i=1;i<n;i++)
        {
            if(a[i]-a[i-1]!=1)
            {
                if(i>1)
                    printf("%d\n",a[i]);
                else if(a[2]-a[1]!=1)
                    printf("%d\n",a[1]);
                else
                    printf("%d\n",a[0]);
                break;
            }
        }
        if(i==n&&a[i]-a[i-1]==1)
            printf("%d\n",a[0]);
    }
    return 0;
}
