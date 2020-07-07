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
    //freopen ("let_it_flow_in.txt","r",stdin);
    //freopen ("let_it_flow_out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int t,n;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        int j;
        string s[3];
        for(j=0;j<3;j++)
            cin>>s[j];
        cout<<"Case #"<<i<<": ";
        if(n%2)
        {
            cout<<"0\n";
            continue;
        }
        if((s[0][0]=='#')||(s[1][0]=='#')||(s[1][n-1]=='#')||(s[2][n-1]=='#'))
        {
            cout<<"0\n";
            continue;
        }
        ll ans=1;
        for(j=1;j<n-1;j++)
        {
            if(j%2)
            {
                if((s[1][j]=='#')||((s[0][j]=='#')&&(s[2][j]=='#')))
                    ans=0;
                else if((s[0][j]=='.')&&(s[2][j]=='.')&&(s[0][j+1]=='.')&&(s[2][j+1]=='.'))
                    ans=(ans*2)%mod;
                else if(((s[0][j]=='#')||(s[0][j+1]=='#'))&&((s[2][j]=='#')||(s[2][j+1]=='#')))
                    ans=0;
            }
            else
            {
                if(s[1][j]=='#')
                    ans=0;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
