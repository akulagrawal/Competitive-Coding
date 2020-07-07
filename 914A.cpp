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
    ll n,p=-MAX,q=0;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            q=sqrt(a[i]);
            if(q*q<a[i]&&((q+1)*(q+1)>a[i]))
                p=max(p,a[i]);
        }
        else
            p=max(p,a[i]);
    }
    cout<<p;
    return 0;
}
