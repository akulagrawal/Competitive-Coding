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

ll a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j,n,start,mid,end1,k;
    ll p,m;
    scanf("%d",&t);
    while(t--)
    {
        k=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        scanf("%lld",&p);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                start=j+1;
                end1=n-1;
                m=p-a[i]-a[j];
                while(start<end1)
                {
                    mid=start+(end1-start)/2;
                    if(a[mid]<m)
                        start=mid+1;
                    else
                        end1=mid;
                }
                mid=start+(end1-start)/2;
                if(a[mid]==m)
                {
                    k=1;
                    break;
                }
            }
            if(k)
                break;
        }
        if(k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
