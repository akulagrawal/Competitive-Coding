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

int x[505];

int main()
{
    int t,a,b,n,p,i,k1,k2;
    cin>>t;
    while(t--)
    {
        a=0;
        b=0;
        cin>>n>>p;
        k1=p/2;
        k2=p/10;
        for(i=0;i<n;i++)
        {
            cin>>x[i];
            if(x[i]>=k1)
                a++;
            else if(x[i]<=k2)
                b++;
        }
        if(a==1&&b==2)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
