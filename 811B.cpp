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

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,l,r,p,sum;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
    {
        cin>>l>>r>>p;
        sum=0;
        for(j=l-1;j<r;j++)
            if(a[j]<a[p-1])
                sum++;
        sum+=l;
        if(sum==p)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
