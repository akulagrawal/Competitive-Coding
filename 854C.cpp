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

struct compare
{
    bool operator()(const pii& l, const pii& r)
    {
        return l.f < r.f;
    }
};

int c[MAX],b[MAX];
priority_queue<pii , vector<pii>, compare> pq;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i;
    pii p;
    ll sum=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>c[i];
    for(i=0;i<k;i++)
        pq.push(mp(c[i],i+1));
    for(i=k;i<k+n;i++)
    {
        if(i<n)
            pq.push(mp(c[i],i+1));
        p=pq.top();
        sum+=(ll)(i+1-p.s)*(ll)p.f;
        b[p.s]=i+1;
        pq.pop();
    }
    cout<<sum<<endl;
    for(i=1;i<=n;i++)
        cout<<b[i]<<" ";
    return 0;
}
