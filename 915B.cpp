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
    int n,pos,l,r,ans=0;
    cin>>n>>pos>>l>>r;
    if(l>1&&r<n)
        ans=min(abs(l-pos),abs(r-pos))+r-l+2;
    else if(l>1)
        ans=abs(l-pos)+1;
    else if(r<n)
        ans=abs(r-pos)+1;
    cout<<ans;
    return 0;
}
