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

ll a[MAX];
map<ll,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q,b,p;
    cin>>n>>q;
    int i;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    	my[a[i]]++;
    }
    while(q--)
    {
    	cin>>b;
    	ll y=0;
    	p=(ll)(1<<30);
    	p*=2;
    	while(b&&p)
    	{
    		if(b>=p)
    		{
    				ll x=b/p;
    				if(my[p]>=x)
    				{
    					y+=x;
    					b-=x*p;
    				}
    				else
    				{
    					y+=my[p];
    					b-=p*my[p];
    				}
    		}
    		p/=2;
    	}
    	if(b)
    		cout<<"-1\n";
    	else
    		cout<<y<<endl;
    }
    return 0;
}