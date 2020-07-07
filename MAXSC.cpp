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

ll a[1003][1003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll sum=0;
        cin>>n;
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j];
        ll p=mod;
        for(i=n-1;i>=0;i--)
        {
            ll maxm=0;
            for(j=0;j<n;j++)
            {
                if(a[i][j]<p)
                    maxm=max(maxm,a[i][j]);
            }
            p=maxm;
            if(!maxm)
            {
                sum=-1;
                break;
            }
            else
                sum+=maxm;
        }
        cout<<sum<<endl;
    }
    return 0;
}
