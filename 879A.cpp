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

int d[1003],s[1003];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,p=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i]>>d[i];
    for(i=0;i<n;i++)
    {
        while(s[i]<=p)
            s[i]+=d[i];
        p=s[i];
    }
    cout<<p;
    return 0;
}
