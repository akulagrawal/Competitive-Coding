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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,n,x,ans,p,i;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        p=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            ans=ans^x;
            p+=x;
        }
        if(p==n)
        {
            if(n%2)
                printf("Brother\n");
            else
                printf("John\n");
        }
        else
        {
            if(!ans)
                printf("Brother\n");
            else
                printf("John\n");
        }
    }
    return 0;
}
