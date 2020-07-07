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


int x[20],y[20],z[20];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    	cin>>x[i];
    int p=0;
    for(j=0;j<m;j++)
    {
    	cin>>y[i];
    	z[y[i]]++;
    }
    for(i=0;i<n;i++)
    	if(z[x[i]])
    		cout<<x[i]<<" ";


    return 0;
}