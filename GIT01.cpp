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

string s[102],s1[102],s2[102];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            if((j+i)%2)
            {
                s1[i].pb('R');
                s2[i].pb('G');
            }
            else
            {
                s1[i].pb('G');
                s2[i].pb('R');
            }
        }
    }
    cin>>t;
    while(t--)
    {
        int p=0,q=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
            cin>>s[i];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j]!=s1[i][j])
                    p+=3*(s1[i][j]=='R')+5*(s1[i][j]=='G');
                if(s[i][j]!=s2[i][j])
                    q+=3*(s2[i][j]=='R')+5*(s2[i][j]=='G');
            }
        }
        cout<<min(p,q)<<endl;
    }
    return 0;
}
