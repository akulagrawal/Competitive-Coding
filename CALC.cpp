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

ll n,b,m,maxm;

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
        cin>>n>>b;
        m=n/2;
        if(!(m%b))
        {
            n-=m;
            m/=b;
            cout<<(n*m)<<endl;
        }
        else
        {
            m/=b;
            m+=1;
            n=n-(m*b);
            maxm=n*m;
            n+=b;
            m-=1;
            maxm=max(maxm,n*m);
            cout<<maxm<<endl;
        }
    }
    return 0;
}
