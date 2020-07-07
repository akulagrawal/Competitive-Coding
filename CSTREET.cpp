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

struct mycomp {
    bool operator()(pii const & a,
                              pii const & b)
    { return a.second>b.second; }
};

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,p,n,m,a,b,c;
    cin>>t;
    priority_queue<pii, vector<pii>, mycomp > pq;
    map<int, int> my;
    vector<pii> v[MAX];
    int sum;
    while(t--)
    {
    	cin>>p>>n>>m;
    	int i;
    	sum = 0;
    	my.clear();
    	for(i=0;i<m;i++)
    	{
    		cin>>a>>b>>c;
    		v[a].pb(mp(b,c));
    		v[b].pb(mp(a,c));
    	}
    	int minm = mod;
    	int mina = 1, minb = v[1][0].f;
    	for(i=1;i<n;i++)
    	{
    		for(int j=0;j<v[i].size();j++)
    		{
    			if(minm > v[i][j].s)
    			{
    				minm = v[i][j].s;
    				mina = i;
    				minb = v[i][j].f;
    			}
    		}
    	}
    	pq.push(mp( minb, minm));
    	my[mina] = 1;

    	while(!pq.empty())
    	{
    		pii temp = pq.top();
    		pq.pop();
    		//cout<<temp.f.f<<" "<<temp.f.s<<" "<<temp.s<<endl;
    		
    		if(!my[temp.f])
    		{
    			my[temp.f] = 1;
    			//cout<<temp.f.f<<" "<<temp.f.s<<endl;
    			sum+=temp.s;
    			for(i=0;i<v[temp.f].size();i++)
    				if(!my[v[temp.f][i].f])
    					pq.push(v[temp.f][i]);
    		}
    	}
    	cout<<p*sum<<endl;
    }
    


    return 0;
}