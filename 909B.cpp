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
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0;
    cin>>n;
    while(1)
    {
        if(n==2||n==1)
        {
            ans+=n;
            break;
        }
        ans+=n;
        n-=2;
    }
    cout<<ans;
    return 0;
}
