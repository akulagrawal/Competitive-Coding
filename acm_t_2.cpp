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

ll a[55];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,j,d;
    ll p,s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        d=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            p=1;
            s=0;
            for(j=i;j<n;j++)
            {
                p*=a[j];
                s+=a[j];
                if(p==s)
                    d++;
            }
        }
        cout<<d<<endl;
    }
    return 0;
}
