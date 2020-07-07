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

string s[MAX];
pair<string,int> p[MAX];
ll BIT[MAX];
int n;

void update(int x,int delta)
{
    for(;x<=(n+1);x+=x&-x)
        BIT[x]+=(ll)delta;
}

ll query(int x)
{
    ll sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT[x];
    return sum;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m;
    ll ans=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    for(i=0;i<n;i++)
    {
        char s1[MAX];
        m=s[i].size();
        for(int j=0;j<m;j++)
            s1[m-j-1]=s[i][j];
        s1[m]='\0';
        p[i]=mp(s1,i+1);
    }
    sort(p,p+n);
    for(i=n-1;i>=0;i--)
    {
        ans+=query(p[i].s);
        update(p[i].s,1);
    }
    cout<<ans;
    return 0;
}
