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

bool is[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int i,j;
    for(i=0;i<26;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if((s[j]-'a')==i)
    		{
    			k--;
    			is[j]=1;
    		}
    		if(!k)
    			break;
    	}
    	if(!k)
    		break;
    }
    for(i=0;i<n;i++)
    {
    	if(!is[i])
    		cout<<s[i];
    }

    return 0;
}