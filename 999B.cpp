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
    for(int i=0;i<n;i++)
    {
    	if(n%(i+1)==0)
    	{
    		for(int j=0;j<=i/2;j++)
    		{
    			char temp=s[j];
    			s[j]=s[i-j];
    			s[i-j]=temp;
    		}
    	}
    }
    cout<<s;
    return 0;
}