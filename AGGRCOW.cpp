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

long x[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int t,n,c,sum,ans,i;
    long low,mid,high,maxm;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&c);
        maxm=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&x[i]);
            maxm=max(maxm,x[i]);
        }
        sort(x,x+n);
        low=1;
        high=maxm-1;
        while(low<high)
        {
            mid=low+(high-low+1)/2;
            ans=0;
            sum=0;
            for(i=1;i<n;i++)
            {
                sum+=x[i]-x[i-1];
                if(sum>=mid)
                {
                    ans++;
                    sum=0;
                }
            }
            if(ans<c-1)
                high=mid-1;
            else
                low=mid;
        }
        mid=low+(high-low)/2;
        printf("%d\n",mid);
    }
    return 0;
}
