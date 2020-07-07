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
int indeg[30],outdeg[30];
int vis[30];

void dfs(int n)
{
    vis[n]=1;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i]);
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,p,q;
    string s;
    cin>>t;
    while(t--)
    {
        p=0;
        q=0;
        for(i=0;i<26;i++)
            v[i].clear();
        memset(indeg,0,sizeof(indeg));
        memset(outdeg,0,sizeof(outdeg));
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s;
            if(s[0]-'a'!=s[s.size()-1]-'a')
            {
                v[s[0]-'a'].pb(s[s.size()-1]-'a');
            }
            outdeg[s[0]-'a']++;
            indeg[s[s.size()-1]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            if(outdeg[i]==indeg[i]+1)
            {
                if(p)
                {
                    p=30;
                    break;
                }
                p=i+1;
            }
            else if(indeg[i]==outdeg[i]+1)
            {
                if(q)
                {
                    q=30;
                    break;
                }
                q=i+1;
            }
            else if(indeg[i]!=outdeg[i])
            {
                p=30;
                q=30;
                break;
            }
        }
        if(p==30||q==30)
        {
            cout<<"The door cannot be opened.\n";
            continue;
        }
        if(p)
            p--;
        if(q)
            q--;
        dfs(p);
        for(i=0;i<26;i++)
        {
            if((outdeg[i]||indeg[i])&&!vis[i])
                break;
        }
        if(i<26)
            cout<<"The door cannot be opened.\n";
        else
            cout<<"Ordering is possible.\n";
    }
    return 0;
}
