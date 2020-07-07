#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    int i;
    cin>>a>>b;
    for(i=1;;i++)
    {
        a*=3;
        b*=2;
        if(a>b)
            break;
    }
    cout<<i;
    return 0;
}
