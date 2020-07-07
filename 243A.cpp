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

ll a[MAX];
bool mark[1<<20];
set<int> b,c;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,u;
    ll x,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        c.clear();
        set<int>::iterator it;
        for(it=b.begin();it!=b.end();it++)
        {
            x=*it;
            c.insert(x|a[i]);
        }
        c.insert(a[i]);
        b.swap(c);
        for(it=b.begin();it!=b.end();it++)
        {
            x=*it;
            if(!mark[x])
            {
                mark[x]=1;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
