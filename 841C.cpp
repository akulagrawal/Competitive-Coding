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

ll a[MAX],b[MAX],c[MAX];
pair<ll,int> p1[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,i;
    cin>>m;
    for(i=0;i<m;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
    {
        cin>>b[i];
        p1[i]=mp(b[i],i);
    }
    sort(p1,p1+m);
    sort(a,a+m);
    for(i=0;i<m;i++)
        c[p1[i].s]=a[m-1-i];
    for(i=0;i<m;i++)
        cout<<c[i]<<" ";
    return 0;
}
