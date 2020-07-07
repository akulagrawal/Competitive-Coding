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
int a[MAX],b[MAX];
bool c[MAX];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    int p,i;
    while(q.size())
    {
        p=q.front();
        q.pop();
        c[p]=1;
        b[p]++;
        for(i=0;i<v[p].size();i++)
        {
            b[v[p][i]]++;
            if(a[v[p][i]]==b[v[p][i]])
                q.push(v[p][i]);
        }
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,x,y,ans=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        if(b[i]==a[i])
            bfs(i);
    }
    for(i=1;i<=n;i++)
    {
        if(c[i])
            ans++;
    }
    cout<<ans<<endl;
    for(i=1;i<=n;i++)
    {
        if(c[i])
            cout<<i<<" ";
    }
    return 0;
}
