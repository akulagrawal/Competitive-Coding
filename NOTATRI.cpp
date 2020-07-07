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

int s[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,l,r,mid,ans;
    while(1)
    {
        scanf("%d",&n);
        ans=0;
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                l=j+1;
                r=n-1;
                while(l<r)
                {
                    mid=l+(r-l)/2;
                    if(s[mid]>(s[j]+s[i]))
                        r=mid;
                    else
                        l=mid+1;
                }
                mid=l+(r-l)/2;
                if(s[mid]<=(s[j]+s[i]))
                    mid++;
                ans+=n-mid;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
