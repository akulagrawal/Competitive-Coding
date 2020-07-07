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

int f[MAX],b[5005][5005];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin>>n;
    int p=0;
    for(i=0;i<n;i++)
    {
        cin>>f[i];
        b[i][f[i]-1]=1;
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[f[i]-1][j]==1&&b[j][i]==1)
                p=1;
        }
    }
    if(p)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
