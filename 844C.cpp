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
int c[MAX];
pair<ll,int> b[MAX];
vector<int> ans[MAX];
int my[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=mp(a[i],i);
    }
    sort(b,b+n);
    for(i=0;i<n;i++)
        c[b[i].s]=i;
    j=0;
    for(i=0;i<n;i++)
    {
        k=i;
        while(!my[c[i]])
        {
            ans[j].pb(i);
            my[i]=1;
            i=c[i];
        }
        if(k!=i)
        {
            ans[j].pb(i);
            my[i]=1;
        }
        i=k;
        j++;
    }
    for(i=0;i<j;i++)
        sum+=(bool)ans[i].size();
    cout<<sum<<endl;
    for(i=0;i<j;i++)
    {
        if(ans[i].size())
        {
            cout<<ans[i].size()<<" ";
            for(int k=0;k<ans[i].size();k++)
                cout<<ans[i][k]+1<<" ";
            cout<<endl;
        }
    }
    return 0;
}
