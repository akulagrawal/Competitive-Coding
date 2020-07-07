#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000005
#define mod 1000000007
#define pb push_back
#define INF 2000000001
#define pii pair<int,int>

ll a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int n,i;
    ll m,low,mid,high,sum;
    scanf("%d%lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    low=0;
    high=INF;
    while(low<high)
    {
        sum=0;
        mid=low+(high-low)/2;
        for(i=0;i<n;i++)
        {
            if(a[i]>mid)
                sum+=a[i]-mid;
            if(sum>m)
                break;
        }
        if(sum>m)
            low=mid+1;
        else
            high=mid;
    }
    mid=low+(high-low)/2;
    sum=0;
    for(i=0;i<n;i++)
        if(a[i]>mid)
            sum+=a[i]-mid;
    if(sum<m)
        mid-=1;
    printf("%lld",mid);
    return 0;
}
