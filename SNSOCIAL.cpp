#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 505
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[MAX][MAX],n,m;
int x[8]={-1,-1,-1,0,0,1,1,1};
int y[8]={-1,0,1,-1,1,-1,0,1};

bool isvalid(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return 1;
    return 0;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int maxm=0,i,j;
        cin>>n>>m;
        queue<pii> q;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
              { cin>>a[i][j];
                 maxm=max(maxm,a[i][j]);
              }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
             if(a[i][j]==maxm)
               q.push(mp(i,j));

        int vis=0,ans=0;
        while(1)
        {
           int siz=q.size();
           pii p;
           while(siz--)
           {
              p=q.front();
              q.pop();
              vis++;
              for(i=0;i<8;i++)
              {
                  if(a[p.f+x[i]][p.s+y[i]]!=maxm && isvalid(p.f+x[i],p.s+y[i]))
                    { q.push(mp(p.f+x[i],p.s+y[i]));
                        a[p.f+x[i]][p.s+y[i]]=maxm;
                    }
              }
           }
           if(vis==n*m)
            break;
           ans++;
        }
        cout<<ans<<endl;

    }

    return 0;
}
