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

int a[MAX],n;
unsigned ll tree[15][MAX];

void update(int x,unsigned ll delta,int k)
{
    for(;x<=n;x+=x&-x)
        tree[k][x]+=delta;
}

unsigned ll sum(int x,int k)
{
    unsigned ll val=0;
    for(;x>0;x-=x&-x)
        val+=tree[k][x];
    return val;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,i,j;
    unsigned ll p1;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        update(a[i],1,1);
        for(j=2;j<=(k+1);j++)
        {
            p1=sum(a[i]-1,j-1);
            update(a[i],p1,j);
        }
    }
    cout<<(unsigned ll)sum(n,k+1);
    return 0;
}
