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

int l[1003],r[1003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    int i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    	cin>>l[i]>>r[i];
    for(i=0;i<n;i++)
    	cout<<i%2;

    return 0;
}