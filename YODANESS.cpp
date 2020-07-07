#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 10000005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[200005],m;
int BIT[MAX];
map<string,int> my;

void update(int x,int delta)
{
    for(;x<=m;x+=x&(-x))
        BIT[x]+=delta;
}

int query(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=BIT[x];
        x-=x&(-x);
    }
    return sum;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,n,maxm;
    ll sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        maxm=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            string s;
            cin>>s;
            my[s]=i+1;
        }
        for(i=0;i<n;i++)
        {
            string s;
            cin>>s;
            a[i]=my[s];
        }
        maxm=a[0];
        for(i=1;i<n;i++)
            if(maxm<a[i])
                maxm=a[i];
        m=maxm+1;
        for(i=n-1;i>=0;i--)
        {
            sum+=(ll)query(a[i]);
            update(a[i],1);
        }
        printf("%lld\n",sum);
        memset(BIT,0,(m+1)*sizeof(int));
    }
    return 0;
}
