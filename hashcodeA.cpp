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

char h[MAX];
int a[MAX];
vector<string> v[MAX];
vector<int> v1,v2;
vector<pair<string, int> > p;
map<string, int> my;

int main()
{
    freopen ("e.txt","r",stdin);
    //freopen ("a_output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int i,j,cnt=0;
    for(i=0;i<n;i++)
    {
    	cin>>h[i]>>a[i];
    	if(h[i]=='H')
    		v1.pb(i);
    	else
    		v2.pb(i);
    	string x;
    	for(j=0;j<a[i];j++)
    	{
    		cin>>x;
    		if(!my[x])
    			cnt++;
    		my[x]=1;
    		v[i].pb(x);
    	}
    	p.pb(mp(v[i][0], i));
    }
    //sort(p,p.begin(),p.end());
    cout<<v1.size()+(v2.size()/2)<<endl;
    for(i=0;i<p.size();i++)
    	if(h[p[i].s] == 'H')
    		cout<<i<<endl;
    for(i=0;i<v2.size();i+=2)
    {
    	if(i<v2.size()-1)
    		cout<<v2[i]<<" "<<v2[i+1]<<endl;
    }
    cout<<endl<<cnt;


    return 0;
}