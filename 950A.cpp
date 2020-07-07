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
    int l,r,a;
    cin>>l>>r>>a;
    if(l+a<=r)
        cout<<2*(l+a);
    else if(r+a<=l)
        cout<<2*(r+a);
    else
        cout<<(l+r+a)-(l+r+a)%2;
    return 0;
}
