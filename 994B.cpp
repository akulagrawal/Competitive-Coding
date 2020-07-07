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

pair<pair<ll,ll>,int> p[MAX];
priority_queue<int, vector<int>, greater<int> > pq;
ll ans[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
    	cin>>p[i].f.f;
    	p[i].s=i;
    }
    for(i=0;i<n;i++)
    	cin>>p[i].f.s;
    sort(p,p+n);
    ll sum=0;
    for(i=0;i<=k;i++)
    {
    	sum+=p[i].f.s;
    	ans[p[i].s]=sum;
    	pq.push(p[i].f.s);
    }
    for(;i<n;i++)
    {
    	
    	
    		sum-=pq.top();
    		sum+=p[i].f.s;
    		pq.pop();
    		pq.push(p[i].f.s);
    	
    	ans[p[i].s]=sum;
    }
    for(i=0;i<n;i++)
    	cout<<ans[i]<<" ";




    return 0;
}