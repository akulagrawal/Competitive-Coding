#include<bits/stdc++.h>
using namespace std;
#define f first
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

string s[200];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c,a1=-1,a2=-1;

    cin>>r>>c;
    int i,j;
    for(i=0;i<r;i++)
    	cin>>s[i];
    for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    	{
    		if((s[i][j]=='B')&&a1==-1)
    			a1=j;
    		if(s[i][j]=='B')
    			a2=j;
    	}
    	if(a2!=-1)
    		break;
    }
    int as=a1+(a2-a1)/2;
    int b=i+(a2-a1)/2;
    cout<<b+1<<" "<<as+1;


    return 0;
}