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
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1)
            cout<<"0"<<endl;
        else if(n==2)
            cout<<m<<endl;
        else
            cout<<n+(2*m)-3<<endl;
    }
    return 0;
}
