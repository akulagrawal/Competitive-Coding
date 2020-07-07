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

map<char,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    my['<']=0;
    my['^']=1;
    my['>']=2;
    my['v']=3;
    char a,b;
    cin>>a;
    cin>>b;
    cin>>n;
    n=n%4;
    if(n==2||n==0)
        cout<<"undefined";
    if(n==1)
    {
        if(my[b]==(my[a]+1)%4)
            cout<<"cw";
        else
            cout<<"ccw";
    }
    else if(n==3)
    {
        if(my[b]==(my[a]+1)%4)
            cout<<"ccw";
        else
            cout<<"cw";
    }
    return 0;
}
