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
cin>>n;
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	for(i=0;i<n;i++)
		sum+=a[i];
	if(n<=1)
	{
		cout<<"-1";
		return 0;
	}
	if(n==2)
	{
		if(a[0]==a[1])
		{
			cout<<"-1";
			return 0;
		}
	}
	if(a[0]*2==sum)
	{
		cout<<"1\n";
		cout<<n;
	}
	else
	{
		cout<<"1\n";
		cout<<"1";
	}


    return 0;
}