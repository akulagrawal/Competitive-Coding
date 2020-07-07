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
    
    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;
    int ans=0,i;
    for(i=0;i<n-1;i++)
    {
    	if((a[i]!=a[i+1])&&(b[i]!=b[i+1])&&(a[i]!=b[i]))
    	{
    		swap(a[i],a[i+1]);
    		ans++;
    	}
    }
    for(i=0;i<n;i++)
    {
    	if(a[i]!=b[i])
    		ans++;
    }
    cout<<ans;


    return 0;
}