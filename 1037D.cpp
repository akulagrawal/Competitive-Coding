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
int a[MAX];
int vis[MAX];
map<pii,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int i;
    for(i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        my[mp(x,y)]=1;
        my[mp(y,x)]=1;
    }
    for(i=0;i<n;i++)
        cin>>a[i];
    if(a[0]!=1)
    {
        cout<<"No";
        return 0;
    }
    queue<int> q;
    q.push(a[0]);
    vis[a[0]]=1;
    for(i=1;i<n;i++)
    {
        if(vis[a[i]])
        {
            cout<<"No";
            return 0;
        }
        vis[a[i]]=1;
        while(!q.empty()&&(my[mp(q.front(),a[i])]==0))
            q.pop();
        if(q.empty())
        {
            cout<<"No";
            return 0;
        }
        q.push(a[i]);
    }
    cout<<"Yes";


    return 0;
}