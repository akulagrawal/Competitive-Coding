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

int d[MAX],l[MAX],s[MAX];

struct compare
{
    bool operator()(const pii& l, const pii& r)
    {
        return l.f < r.f;
    }
};

pair<int,pii> a[MAX];
priority_queue< pii, vector<pii>, compare > pq;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,x,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&d[i],&l[i],&s[i]);
            a[i]=mp(d[i],mp(l[i],s[i]));
        }
        sort(a,a+n);
        i=0;
        x=0;
        while(1)
        {
            int p=a[i].f;
            while(i<n&&a[i].f==p)
            {
                pq.push(mp(a[i].s.s,a[i].s.f));
                i++;
            }
            while(!pq.empty()&&((i<n&&p!=a[i].f)||(i>=n&&p!=(m+1))))
            {
                pii k=pq.top();
                pq.pop();
                if(i<n)
                {
                    if((p+k.s-1)<a[i].f)
                        p+=k.s;
                    else
                    {
                        k.s-=(a[i].f-p);
                        p=a[i].f;
                        pq.push(k);
                    }
                }
                else
                {
                    if((p+k.s-1)<=m)
                        p+=k.s;
                    else
                    {
                        k.s-=(m+1-p);
                        p=m+1;
                        pq.push(k);
                    }
                }
            }
            if(i>=n)
                break;
        }
        while(!pq.empty())
        {
            ans+=pq.top().s*pq.top().f;
            pq.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}
