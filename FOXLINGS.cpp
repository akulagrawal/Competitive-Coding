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
vector<int> ans;
map<int,int> my;

void dfs(int n)
{
    my[n]=0;
    for(int i=0;i<v[n].size();i++)
    {
        if(my[v[n][i]])
            dfs(v[n][i]);
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,x,y,sum=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        if(!my[x])
        {
            my[x]=1;
            ans.pb(x);
        }
        if(!my[y])
        {
            my[y]=1;
            ans.pb(y);
        }
    }
    for(i=0;i<ans.size();i++)
    {
        if(my[ans[i]])
        {
            sum++;
            dfs(ans[i]);
        }
    }
    printf("%d",n-ans.size()+sum);
    return 0;
}
