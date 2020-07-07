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
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int k=0,maxm=b[0],minm=b[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<=maxm)
            maxm=max(maxm,b[i]);
    }
    if(a[i]==0&&maxm>=m)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
