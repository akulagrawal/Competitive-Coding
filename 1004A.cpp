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

ll x[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll d;
    cin>>n>>d;
    int i;
    for(i=0;i<n;i++)
    	cin>>x[i];
    sort(x,x+n);
    ll p=2;
    for(i=1;i<n;i++)
    	if(x[i]-x[i-1]==2*d)
    		p++;
    	else if(x[i]-x[i-1]>2*d)
    		p+=2;
    cout<<p;


    return 0;
}