#include<bits/stdc++.h>
using namespace std;
#define f second.first
#define s second.second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int block;

bool sortmod(const pair<int,pii> &a, const pair<int,pii> &b)
{
    int ax=a.f/block;
    int bx=b.f/block;
    if(ax!=bx)
        return ax<bx;
    else
        return a.s<b.s;
}

int a[MAX];
pair<int,pii> b[MAX];
int my[MAX];
int ans[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,x,y,l=0,r=0,sum=1;
    scanf("%d",&n);
    block=sqrt(n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    my[a[0]]=1;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        b[i]=mp(i,mp(x-1,y-1));
    }
    sort(b,b+m,sortmod);
    for(i=0;i<m;i++)
    {
        while(l<b[i].f)
        {
            my[a[l]]--;
            if(!my[a[l]])
                sum--;
            l++;
        }
        while(l>b[i].f)
        {
            l--;
            if(!my[a[l]])
                sum++;
            my[a[l]]++;
        }
        while(r<b[i].s)
        {
            r++;
            if(!my[a[r]])
                sum++;
            my[a[r]]++;
        }
        while(r>b[i].s)
        {
            my[a[r]]--;
            if(!my[a[r]])
                sum--;
            r--;
        }
        ans[b[i].first]=sum;
    }
    for(i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
