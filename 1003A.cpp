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

int a[MAX],b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int i;
    int maxm=0;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    	b[a[i]]++;
    	maxm=max(maxm,b[a[i]]);
    }
    cout<<maxm;
    return 0;
}