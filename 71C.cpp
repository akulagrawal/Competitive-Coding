#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k,m;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=3;i<=n;i++)
    {
        if(n%i)
            continue;
        m=n/i;
        for(j=0;j<m;j++)
        {
            for(k=j;k<n;k+=m)
            {
                if(!a[k])
                    break;
            }
            if(k>=n)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
