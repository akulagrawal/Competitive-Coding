#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

ll a[MAX],b[MAX],h[MAX];
pair<ll,ll> ba[MAX],bh[MAX];

int main()
{
    int n,i;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>h[i];
        ba[i]=mp(b[i],a[i]);
        bh[i]=mp(b[i],h[i]);
    }
    sort(b,b+n);
    sort(b,b+n);

    return 0;
}
