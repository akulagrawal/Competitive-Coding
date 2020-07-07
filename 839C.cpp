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

vector<int> v[MAX];
vector< pair<int,double> > u;
int vis[MAX];

void dfs(int n,int k,double prob)
{
    vis[n]=1;
    int p=0;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            p++;
    }
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i],k+1,prob/(double)p);
    }
    if(p==0)
        u.pb(mp(k,prob));
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x,y;
    double p=0,k=0;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0,1.0);
    n=u.size();
    for(i=0;i<n;i++)
    {
        p+=(double)u[i].f*u[i].s;
        k+=u[i].s;
    }
    p/=k;
    printf("%.10lf",p);
    return 0;
}
