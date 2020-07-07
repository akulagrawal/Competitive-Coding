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

int a[MAX];
vector<int> v;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,b;
    int i;
    cin>>n>>b;
    for(i=0;i<n;i++)
    	cin>>a[i];
    int t=0;
    for(i=0;i<n;i++)
    {
    	if(a[i]%2)
    		t++;
    	else
    		t--;
    	if(t==0&&i<n-1)
    		v.pb(abs(a[i+1]-a[i]));
    }
    if(v.size()==0)
    {
    	cout<<"0";
    	return 0;
    }
    
    sort(v.begin(),v.end());
    int ans=0;
    for(i=0;i<v.size();i++)
    {
    	if(v[i]>b)
    		break;
    	
    	ans++;
    	b-=v[i];
    }
    cout<<ans;




    return 0;
}