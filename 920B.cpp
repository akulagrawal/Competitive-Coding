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

bool sortbysec(const pair<pii,int> &a,
              const pair<pii,int> &b)
{
    if(a.f.f!=b.f.f)
        return (a.f.f < b.f.f);
    return a.s < b.s;
}

int l[5005],r[5006];
pair<pii,int> my[5005];
int ans[5005];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,j;
        for(i=0;i<n;i++)
        {
            cin>>l[i]>>r[i];
            my[i]=mp(mp(l[i],r[i]),i);
        }
        sort(my,my+n,sortbysec);
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(my[i].f.f>cnt)
            {
                ans[my[i].s]=my[i].f.f;
                cnt=my[i].f.f;
            }
            else if(cnt>=my[i].f.s)
                ans[my[i].s]=0;
            else
            {
                cnt++;
                ans[my[i].s]=cnt;
            }
        }
        for(i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
