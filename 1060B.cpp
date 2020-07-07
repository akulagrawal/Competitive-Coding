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
    
    ll n;
    cin>>n;
    string s;
    int ans=0;
    int x,c=0,c2=0;
    while(n)
    {
    	x=n%10;
    	if(x==0&&c>0)
    		c2=1;
    	else
    		c2=0;
    	x=(x+10-c)%10;
    	ans+=9+((x+1)%10);
    	if(x<9||c2>0)
    		c=1;
    	else
    		c=0;
    	n/=10;
    	if((!n)&&c)
    		ans-=10;
    	
    }
    cout<<ans;



    return 0;
}