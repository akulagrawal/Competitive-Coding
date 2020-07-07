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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
    	ll a,b;
    	cin>>a>>b;
    	if(a-b!=1)
    		cout<<"NO";
    	else
    	{
    		ll c=a+b;
    		ll i;
    		for(i=2;i<=sqrt(c);i++)
    		{
    			if(c%i==0)
    			{
    				cout<<"NO";
    				break;
    			}
    		}
    		if(i>sqrt(c))
    			cout<<"YES";
    	}
    	cout<<endl;
    }


    return 0;
}