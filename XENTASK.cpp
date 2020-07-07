#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 20005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int x[MAX];

int main()
{
    int t,n,i,sum1,sum2;
    scanf("%d",&t);
    while(t--)
    {
        sum1=0;
        sum2=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            if(i%2)
                sum1+=x[i];
            else
                sum2+=x[i];
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            if(i%2)
                sum2+=x[i];
            else
                sum1+=x[i];
        }
        printf("%d\n",min(sum1,sum2));
    }
    return 0;
}
