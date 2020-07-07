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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,d,D,a,b,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>d>>D;
        if(m>=(n*d)&&m<=(n*D))
        {
            a=m/n;
            b=m%n;
            for(i=1;i<=b;i++)
            {
                for(j=0;j<a+1;j++)
                    cout<<i<<" "<<(i+j-1)%n+1<<endl;
            }
            for(;i<=n;i++)
            {
                for(j=0;j<a;j++)
                    cout<<i<<" "<<(i+j-1)%n+1<<endl;
            }
        }
        else
            cout<<"-1\n";
    }
    return 0;
}
