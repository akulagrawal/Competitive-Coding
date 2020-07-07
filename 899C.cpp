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
    int n,i;
    cin>>n;
    if(n%2==0)
    {
        if(n%4==0)
            cout<<"0\n";
        else
            cout<<"1\n";
        cout<<n/2<<" ";
        for(i=1;i<=n/2;i+=2)
            cout<<i<<" ";
        int m=n/2;
        m+=2;
        for(i=n;i>=m;i-=2)
            cout<<i<<" ";
    }
    else
    {
        int k=n/4,l=n%4;
        if(l==1||l==2)
            cout<<"1\n";
        else
            cout<<"0\n";
        cout<<(2*k)+l/2<<" ";
        for(i=0;i<k;i++)
            cout<<n-4*i<<" "<<n-4*i-3<<" ";
        if(l==2)
            cout<<"1";
        else if(l==3)
            cout<<"3";
    }
    return 0;
}
