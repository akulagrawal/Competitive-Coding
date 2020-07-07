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

string s[2003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    int i,j;
    for(i=0;i<n;i++)
        cin>>s[i];
    int sum=0;
    int ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='*')
            {
                if(sum>=k)
                    ans+=sum-k+1;
                sum=0;
            }
            else
                sum++;
        }
        if(sum>=k)
            ans+=sum-k+1;
        sum=0;
    }
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            if(s[i][j]=='*')
            {
                if(sum>=k)
                    ans+=sum-k+1;
                sum=0;
            }
            else
                sum++;
        }
        if(sum>=k)
            ans+=sum-k+1;
        sum=0;
    }
    if(k>1)
        cout<<ans;
    else
        cout<<ans/2;
    return 0;
}
