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

int p[MAX],c[MAX];
vector<int> v[MAX];
int ans;

void dfs(int n,int k)
{
    if(k!=c[n])
        ans++;
    int x=c[n];
    c[n]=0;
    for(int i=0;i<v[n].size();i++)
    {
        if(c[v[n][i]])
            dfs(v[n][i],x);
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>p[i];
        v[i+2].pb(p[i]);
        v[p[i]].pb(i+2);
    }
    for(i=1;i<=n;i++)
        cin>>c[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}
