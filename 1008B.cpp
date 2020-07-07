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

ll w[MAX],h[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    	cin>>w[i]>>h[i];
    ll p=max(w[0],h[0]);
    for(i=1;i<n;i++)
    {
    	if(max(w[i],h[i])<=p)
    		p=max(w[i],h[i]);
    	else if(min(w[i],h[i])<=p)
    		p=min(w[i],h[i]);
    	else
    		break;
    }
    if(i<n)
    	cout<<"NO";
    else
    	cout<<"YES";

    return 0;
}