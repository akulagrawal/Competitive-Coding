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
    int n,l,r;

    cin>>n>>l>>r;
    int minsum=0;
    int maxsum=0;
    int prod = 1;
    for(int i=0;i<l;i++)
    {
    	minsum+=prod;
    	maxsum+=prod;
    	prod*=2;
    }
    for(int i=l;i<r;i++)
    {
    	maxsum+=prod;
    	prod*=2;
    }
    prod/=2;
    minsum += (n-l);
    maxsum += (n-r)*prod;
    cout<<minsum<<" "<<maxsum;


    return 0;
}