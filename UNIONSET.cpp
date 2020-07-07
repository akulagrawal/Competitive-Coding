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

int l[2504],m[2504][2504],p[2504];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k,i,j,x,ans;
    ll q;
    cin>>t;
    while(t--)
    {
        memset(p,0,sizeof(p));
        cin>>n>>k;
        ans=0;
        q=0;
        for(i=0;i<n;i++)
        {
            cin>>l[i];
            for(j=0;j<l[i];j++)
                cin>>m[i][j];
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                q++;
                for(x=0;x<l[i];x++)
                    p[m[i][x]]=q;
                for(x=0;x<l[j];x++)
                    p[m[j][x]]=q;
                for(x=1;x<=k;x++)
                    if(p[x]!=q)
                        break;
                if(x==k+1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
