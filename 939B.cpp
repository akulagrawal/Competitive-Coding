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

ll a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    int k;
    cin>>n>>k;
    int i;
    ll p,q,r;
    for(i=0;i<k;i++)
        cin>>a[i];
    p=n%a[0];
    q=1;
    r=n/a[0];
    for(i=1;i<k;i++)
    {
        if(n%a[i]<p)
        {
            p=n%a[i];
            q=i+1;
            r=n/a[i];
        }
    }
    cout<<q<<" "<<r;
    return 0;
}
