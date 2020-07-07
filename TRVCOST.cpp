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
#define pii pair<long,long>

vector<pii> v[MAX];
ll d[MAX];

void dijkstra(int start)
{
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(0,start));
    d[start]=0;
    ll a,b,c,i;
    while(pq.size())
    {
        c=pq.top().f;
        a=pq.top().s;
        pq.pop();
        if(d[a]<c)
            continue;
        for(i=0;i<v[a].size();i++)
        {
            if((d[a]+v[a][i].s)<d[v[a][i].f])
            {
                d[v[a][i].f]=d[a]+v[a][i].s;
                pq.push(mp(d[v[a][i].f],v[a][i].f));
            }
        }
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,w,u,q,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&w);
        v[a].pb(mp(b,w));
        v[b].pb(mp(a,w));
    }
    for(i=0;i<=n;i++)
        d[i]=mod;
    scanf("%lld",&u);
    dijkstra(u);
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&w);
        if(d[w]<MAX)
        {
            printf("%lld\n",d[w]);
            continue;
        }
        printf("NO PATH\n");
    }
    return 0;
}
