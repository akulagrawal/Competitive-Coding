#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int b[30][MAX];
ll dp[30][30];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size(),i,j;
    ll maxm=0;
    for(i=n-1;i>=0;i--)
        b[s[i]-'a'][i]++;
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<26;j++)
            b[j][i]+=b[j][i+1];
    }
    for(i=0;i<n-1;i++)
    {
        j=s[i]-'a';
        for(int k=0;k<26;k++)
        {
            //if(j!=k)
                dp[j][k]+=(ll)b[k][i+1];
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
            maxm=max(maxm,dp[i][j]);
    }
    cout<<maxm;
    return 0;
}
