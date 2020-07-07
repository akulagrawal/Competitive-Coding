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
    long n;
    int k,i=0,r,ans=0,j=0;
    cin>>n>>k;
    while(j<k)
    {
        if(!n)
            break;
        r=n%10;
        if(r)
            ans++;
        else
            j++;
        n/=10;
    }
    if(j!=k&&j>0)
        ans+=j-1;
    cout<<ans;
    return 0;
}
