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

int x[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n,k,minm;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int i;
        for(i=0;i<k;i++)
            cin>>x[i];
        minm=0;
        for(i=1;i<k;i++)
            minm=max(minm,x[i]-x[i-1]);
        minm=(minm+2)/2;
        minm=max(minm,max(n-x[k-1]+1,x[0]));
        cout<<minm<<endl;
    }
    return 0;
}
