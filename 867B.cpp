#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000000
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
    int a;
    cin>>a;
    if(a!=1)
    {
        cout<<2*(a-1)<<" "<<2<<endl;
        cout<<"1 2";
    }
    else
    {
        cout<<"1 1\n";
        cout<<"1";
    }
    return 0;
}
