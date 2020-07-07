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

string s;

int main()
{
    //freopen ("ethan_searches_for_a_stringin.txt","r",stdin);
    //freopen ("ethan_searches_for_a_stringout.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int i,j,k;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	cin>>s;
    	string z="",w="";
    	w+=s[0];
    	cout<<"Case #"<<j<<": ";
    	for(i=1;i<s.size();i++)
    	{
    		if(s[i]==s[0])
    		{
    			string z=w+s;
    			for(k=0;k<s.size();k++)
    				if(s[k]!=z[k])
    					break;
    			if(k<s.size())
    			{
    				cout<<z<<endl;
    				break;
    			}
    		}
    		w+=s[i];
    	}
    	if(i>=s.size())
    		cout<<"Impossible\n";
    }


    return 0;
}