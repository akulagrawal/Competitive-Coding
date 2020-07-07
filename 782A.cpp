#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 200005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int x[MAX];
bool vis[MAX];

int main()
{
    int n,i,sum=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<2*n;i++)
        scanf("%d",&x[i]);
    for(i=0;i<2*n;i++)
    {
        if(!vis[x[i]])
        {
            vis[x[i]]=1;
            sum++;
        }
        else
        {
            vis[x[i]]=0;
            sum--;
        }
        if(sum>ans)
            ans=sum;
    }
    printf("%d",ans);
    return 0;
}
