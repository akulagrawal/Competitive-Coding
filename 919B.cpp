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
    int k,i;
    ll n=1,m=1;
    cin>>k;
    while(1)
    {
        int sum=0;
        n=m;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        if(sum==10)
            k--;
        if(!k)
        {
            cout<<m;
            break;
        }
        m++;
    }
    return 0;
}
