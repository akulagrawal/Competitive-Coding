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

double x[MAX],y[MAX],r[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    double r2,d,f;
    int n,k=0,j,i;
    cin>>r2>>d;
    cin>>n;
    for(j=0;j<n;j++)
    {
        cin>>x[j];
        cin>>y[j];
        cin>>r[j];
    }
    for(i=0;i<n;i++)
    {
        f=sqrt(x[i]*x[i]+y[i]*y[i]);
        f-=(r2-d);
        if((f>=r[i])&&(d-f)>=r[i])
            k++;
    }
    cout<<k;
    return 0;
}
