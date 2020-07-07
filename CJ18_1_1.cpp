#include<bits/stdc++.h>
using namespace std;
#define f first
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int main()
{
    //freopen ("A-large-practice.in","r",stdin);
    //freopen ("A-large-practice.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    int i,j;
    string s;
    for(j=1;j<=t;j++)
    {
    	cin>>s;
    	cout<<"Case #"<<j<<": ";
    	ll x=0,y=0,z=0;
    	for(i=0;i<s.size();i++)
    	{
    		if((s[i]-'0')%2)
    			break;
    		x=x*10+s[i]-'0';
    		y=y*10+s[i]-'0';
    		z=z*10+s[i]-'0';
    	}
    	if(i==s.size())
    		cout<<"0\n";
    	else
    	{
    		x=x*10+(s[i]-'0'+1)%10;
    		y=y*10+(s[i]-'0'-1);
    		z=z*10+(s[i]-'0');
    		for(int k=i+1;k<s.size();k++)
    		{
    			x=x*10;
    			y=y*10+8;
    			z=z*10+s[k]-'0';
    		}
    		cout<<min(abs(z-x),abs(z-y))<<endl;
    	}

    }


    return 0;
}