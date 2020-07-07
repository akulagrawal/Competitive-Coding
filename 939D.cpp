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
bool vis[MAX];
int my[5000][5000];

int dfs(int n)
{
    vis[n]=1;
    int p=0;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
        {
            my[n][v[n][i]]=1;
            p+=dfs(v[n][i]);
        }
    }
    return p;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    n=a.size();
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            v[a[i]].pb(b[i]);
            v[b[i]].pb(a[i]);
        }
    }
    int p=0;
    for(i=0;i<26;i++)
    {
        if(!vis['a'+i])
            dfs('a'+i);
    }
    int j;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            if(my['a'+i]['a'+j]==1)
                p++;
        }
    }
    cout<<p<<endl;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            if(my['a'+i]['a'+j]==1)
                cout<<(char)('a'+i)<<" "<<(char)('a'+j)<<endl;
        }
    }
    return 0;
}
