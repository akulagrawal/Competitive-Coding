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

string s[50];

int main()
{
    //freopen ("touristin.txt","r",stdin);
    //freopen ("touristout.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    int k,n;
    ll v;
    int i,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	cin>>n>>k>>v;
    	cout<<"Case #"<<j<<": ";
    	for(i=0;i<n;i++)
    		cin>>s[i];
    	v--;
    	v=v*(ll)k;
    	v=v%n;
    	if((v+k)<=n)
    		for(i=v;i<v+k;i++)
    			cout<<s[i%n]<<" ";
    	else
    	{
    		for(i=0;i<(v+k)%n;i++)
    			cout<<s[i]<<" ";
    		for(i=v;i<n;i++)
    			cout<<s[i]<<" ";
    	}
    	cout<<endl;
    }

    return 0;
}