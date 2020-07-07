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
    int s,v1,v2,t1,t2,k1,k2;
    cin>>s>>v1>>v2>>t1>>t2;
    k1=2*t1+(s*v1);
    k2=2*t2+(s*v2);
    if(k1<k2)
        cout<<"First";
    else if(k2<k1)
        cout<<"Second";
    else
        cout<<"Friendship";
    return 0;
}
