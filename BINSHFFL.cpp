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

    int t;
    ll a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<"0\n";
            continue;
        }
        if(b==0||(a&&(b==1)))
        {
            cout<<"-1\n";
            continue;
        }
        int n=0,m=0;
        ll y=a;
        while(y)
        {
            if(y%2)
                n++;
            y/=2;
        }
        y=b;
        while(y)
        {
            if(y%2)
                m++;
            y/=2;
        }
        int x=0;
        while(b&&(b%2==0))
        {
            b/=2;
            x++;
        }
        x+=m-1;
        if(n==x)
            cout<<"1\n";
        else if(n<x)
            cout<<x-n+1<<endl;
        else
            cout<<"2\n";
    }

    return 0;
}
