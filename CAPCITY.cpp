#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

vector<int> v[MAX],u[MAX],print;
stack<int> mystack;
bitset<MAX> vis(0),avis(0),bvis(0);
int no=0,c=0;

void dfs1(int n)
{
    vis[n]=1;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs1(v[n][i]);
    }
    mystack.push(n);
}

void dfs2(int n)
{
    print.pb(n);
    vis[n]=1;
    bvis[n]=1;
    no++;
    for(int i=0;i<u[n].size();i++)
    {
        if(!vis[u[n][i]])
            dfs2(u[n][i]);
    }
}

void dfs3(int n)
{
    avis[n]=1;
    if(!bvis[n])
    {
        c++;
        return;
    }
    for(int i=0;i<v[n].size();i++)
    {
        if(!avis[v[n][i]])
            dfs3(v[n][i]);
    }
}

int main()
{
    int n,m,a,b,i,t,c1=0,c2=0,sum;
    bool p=0;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        v[a].pb(b);
        u[b].pb(a);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    vis.reset();
    while(!mystack.empty())
    {
        no=0;
        c=0;
        t=mystack.top();
        mystack.pop();
        if(vis[t])
            continue;
        dfs2(t);
        dfs3(t);
        if(c==0)
        {
            if(p==1)
            {
                printf("0\n");
                return 0;
            }
            p=1;
            c1=no;
            c2=t;
        }
        if(c1==0&&c2==0)
            print.clear();
        bvis.reset();
        avis.reset();
    }
    printf("%d\n",c1);
    sort(print.begin(),print.end());
    for(i=0;i<print.size();i++)
        printf("%d ",print[i]);
    return 0;
}
