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

ll C[1003][1003];

ll binomialCoeff(int n, int k)
{
    int i, j;
    if(C[n][k]||k>n)
        return C[n][k];
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
    return C[n][k];
}

int b[5]={1,2,3,7};

vector<int> v[1003];

ll func(string s,int k)
{
    int n=s.size();
    int p=0;
    int i;
    for(i=0;i<n;i++)
        if(s[i]=='1')
            p++;
    ll sum=0;
    if(p==k)
        sum=1;
    int q=1;
    for(i=1;i<n;i++)
    {
        if(s[i]=='1')
        {
            sum=(sum+binomialCoeff(n-i-1,k-q))%mod;
            q++;
        }
    }
    return sum;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    int k;
    cin>>k;
    if(k>5)
    {
        cout<<"0";
        return 0;
    }
    int i;
    for(i=2;i<=n;i++)
    {
        int p=__builtin_popcount(i);
        v[p].pb(i);
    }
    ll ans=0;
    if(k==0)
        cout<<"1";
    else if(k==1)
        cout<<n-1;
    else if(k==2)
    {
        for(i=0;i<v[1].size();i++)
        {
            ans=(ans+binomialCoeff(n-1,v[1][i]))%mod;
            ans=(ans+func(s,v[1][i]))%mod;
        }
        cout<<ans;
    }
    else if(k==5)
    {
        for(i=0;i<v[7].size();i++)
        {
            ans=(ans+binomialCoeff(n-1,v[7][i]))%mod;
            ans=(ans+func(s,v[7][i]))%mod;
        }
        cout<<ans;
    }
    else if(k==3)
    {
        int j;
        for(i=0;i<v[1].size();i++)
        {
            for(j=0;j<v[v[1][i]].size();j++)
            {
                ans=(ans+binomialCoeff(n-1,v[v[1][i]][j]))%mod;
                ans=(ans+func(s,v[v[1][i]][j]))%mod;
            }
        }
        cout<<ans;
    }
    else if(k==4)
    {
        int j;
        for(i=0;i<v[2].size();i++)
        {
            for(j=0;j<v[v[2][i]].size();j++)
            {
                ans=(ans+binomialCoeff(n-1,v[v[2][i]][j]))%mod;
                ans=(ans+func(s,v[v[2][i]][j]))%mod;
            }
        }
        cout<<ans;
    }
    return 0;
}
