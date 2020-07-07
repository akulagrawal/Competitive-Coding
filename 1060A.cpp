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
    string s;
    cin>>n>>s;
    int i;
    int p=0;
    for(i=0;i<n;i++)
    {
    	if(s[i]=='8')
    		p++;
    }
    int m=(n-p)/10;
    if(p>m)
    {
    	cout<<n/11;
    }
    else
    	cout<<min(p,m);


    return 0;
}