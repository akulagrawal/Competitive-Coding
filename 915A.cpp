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
    int n,k,i,p=1;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(k%a[i]==0)
            p=max(p,a[i]);
    }
    cout<<k/p;
    return 0;
}
