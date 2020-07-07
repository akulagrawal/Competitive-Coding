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

int lcs[5003][5003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(i=0;i<=n;i++)
            lcs[i][0]=0;
        for(i=0;i<=m;i++)
            lcs[0][i]=0;
        string a,b,c,d;
        cin>>a>>b;
        c=a;
        d=b;
        c[0]=a[0];
        j=1;
        for(i=1;i<n;i++)
            if(a[i]!=a[i-1])
            {
                c[j]=a[i];
                j++;
            }
        n=j;
        d[0]=b[0];
        j=1;
        for(i=1;i<m;i++)
            if(b[i]!=b[i-1])
            {
                d[j]=b[i];
                j++;
            }
        m=j;
        int i,j;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    continue;
                if(c[i-1]==d[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        cout<<n+m-lcs[n][m]<<endl;
    }
    return 0;
}
