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
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i;
    string t="";
    int p=0;
    int q=0;
    for(i=0;i<n;i++)
    {
    	t=t+s[i];
    	if(s[i]=='(')
    	{
    		p++;
    		q++;
    	}
    	else
    		q--;
    	if(p==k/2)
    		break;
    }
    for(i=0;i<q;i++)
    	t=t+")";
    cout<<t;


    return 0;
}