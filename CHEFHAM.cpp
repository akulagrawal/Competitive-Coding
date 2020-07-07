#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[MAX],b[MAX];
vector<int> x,y,z[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,ans,p,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        memset(b,0,sizeof(b));
        x.clear();
        y.clear();
        for(i=0;i<MAX;i++)
            z[i].clear();
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            z[a[i]].pb(i);
            b[a[i]]++;
        }
        for(i=0;i<MAX;i++)
        {
            if(b[i]==1)
                x.pb(i);
            else if(b[i]==2)
                y.pb(i);
        }
        p=x.size();
        q=y.size();
        ans=x.size()/2;
        ans*=2;
        for(i=0;i<p-1;i+=2)
            swap(a[z[x[i]][0]],a[z[x[i+1]][0]]);
        for(i=0;i<q-1;i+=2)
        {
            swap(a[z[y[i]][0]],a[z[y[i+1]][0]]);
            swap(a[z[y[i]][1]],a[z[y[i+1]][1]]);
            ans+=4;
        }
        if(p%2)
        {
            ans++;
            if(x[p-1]!=x[0])
                swap(a[z[x[p-1]][0]],a[z[x[0]][0]]);
            else if(q)
                swap(a[z[x[p-1]][0]],a[z[y[q-1]][0]]);
            else
                ans--;
        }
        if(q%2)
        {
            ans+=2;
            if(y[q-1]!=y[0])
            {
                swap(a[z[y[q-1]][0]],a[z[y[0]][0]]);
                swap(a[z[y[q-1]][1]],a[z[y[0]][1]]);
            }
            else if(p>1)
            {
                swap(a[z[x[0]][0]],a[z[y[q-1]][0]]);
                swap(a[z[x[1]][0]],a[z[y[q-1]][1]]);
            }
            else if(p)
            {
                swap(a[z[x[0]][0]],a[z[y[q-1]][1]]);
                ans--;
            }
            else
                ans-=2;
        }
        cout<<ans<<endl;
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
