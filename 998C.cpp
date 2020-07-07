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

vector<int> v;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int m=s.size();
    int sum=0;
    int i;
    for(i=0;i<m;i++)
    {
    	if(s[i]=='0')
    		sum++;
    	else
    	{
    		if(sum)
    			v.pb(sum);
    		sum=0;
    	}
    }
    if(sum)
    	v.pb(sum);
    int d=v.size();
    int cnt=0;
    while(d>1)
    {
    	cnt+=d/2;
    	d=(d+1)/2;
    }
    ll ans1=(cnt*x)+y;
    ll ans2=v.size()*y;
    cout<<min(ans1,ans2);



    return 0;
}