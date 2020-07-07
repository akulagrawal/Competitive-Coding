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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    cin>>n>>s;
    int p=0;
    if(n==1)
    {
    	cout<<"Yes";
    	return 0;
    }
    for(int i=0;i<n;i++)
    {
    	a[s[i]]++;
    	if(a[s[i]]>1)
    		p=1;
    }
    if(p)
    	cout<<"Yes";
    else
    	cout<<"No";


    return 0;
}