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

ll x[MAX], y[MAX];

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
    for(i=0;i<m;i++)
        cin>>y[i];
    i=0;
    j=0;
    ll x1=0, x2=0;
    int k=0;
    while(i<n&&j<m)
    {
        if(x1<=x2)
        {
            x1+=x[i];
            i++;
        }
        else
        {
            x2+=y[j];
            j++;
        }
        if(x1==x2)
        {
            k++;
            x1=0;
            x2=0;
        }
    }
    cout<<k+1;
    return 0;
}
