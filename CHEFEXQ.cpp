#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1050006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[MAX],b[MAX];
int c[320][MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,i,j,x,y,z;
    cin>>n>>q;
    for(i=0;i<n;i++)
        cin>>a[i];
    int bsize=sqrt(n);
    int m=ceil(n/bsize);
    for(i=0;i<m;i++)
    {
        b[i*bsize]=a[i*bsize];
        c[i][b[i*bsize]]++;
        for(j=1;j<bsize;j++)
        {
            int idx=i*bsize+j;
            if(idx>=n)
                break;
            b[idx]=b[idx-1]^a[idx];
            c[i][b[idx]]++;
        }
        if(j<bsize)
            break;
    }
    while(q--)
    {
        cin>>x>>y>>z;
        y--;
        int sno=y/bsize;
        if(x==1)
        {
            c[sno][b[y]]--;
            a[y]=z;
            if(y%bsize)
                b[y]=b[y-1]^z;
            else
                b[y]=z;
            c[sno][b[y]]++;
            for(i=y+1;i<(sno+1)*bsize;i++)
            {
                c[sno][b[i]]--;
                b[i]=b[i-1]^a[i];
                c[sno][b[i]]++;
            }
        }
        else
        {
            int k=0,ans=0;
            if(sno)
            {
                ans=c[0][z];
                k=b[bsize-1];
            }
            for(i=1;i<sno;i++)
            {
                ans+=c[i][z^k];
                k^=b[(i+1)*bsize-1];
            }
            for(i=sno*bsize;i<=y;i++)
            {
                k^=a[i];
                if(k==z)
                    ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
