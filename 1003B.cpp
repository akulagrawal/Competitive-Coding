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

    int a,b,x;
    cin>>a>>b>>x;
    int i,p=0;
    string s;
    if(a>b)
    	p=1;
    for(i=0;i<x-1;i++)
    {
    	if(i%2==p)
    	{
    		s+='1';
    		b--;
    	}
    	else
    	{
    		s+='0';
    		a--;
    	}
    }
    if(i%2==p)
    {
    	while(b--)
    		s+='1';
    	while(a--)
    		s+='0';
    }
    else
    {
    	while(a--)
    		s+='0';
    	while(b--)
    		s+='1';
    }
    cout<<s;
    return 0;
}