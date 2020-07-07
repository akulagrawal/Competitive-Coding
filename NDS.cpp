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

int a[MAX],b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,l,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&len);
        b[len-1]=-1;
        b[0]=a[0];
        l=1;
        for(i=1;i<n;i++)
        {
            if(a[i]<=b[0])
                b[0]=a[i];
            else if(a[i]>=b[l-1])
            {
                l++;
                b[l-1]=a[i];
            }
            else
            {
                int lo=0,hi=l-1,mid;
                while(lo<hi)
                {
                    mid=lo+(hi-lo)/2;
                    if(b[mid]<a[i])
                        lo=mid+1;
                    else
                        hi=mid;
                }
                b[lo]=a[i];
            }
        }
        printf("%d\n",b[len-1]);
    }
    return 0;
}
