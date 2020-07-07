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

int a[200];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,p=0,sum=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        if((a[i]+p)>8)
        {
            sum+=8;
            p+=a[i]-8;
        }
        else
        {
            sum+=a[i]+p;
            p=0;
        }
        if(sum>=k)
            break;
    }
    if(i<n)
        cout<<i+1;
    else
        cout<<"-1";
    return 0;
}
