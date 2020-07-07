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
    int t;
    cin>>t;
    int x1,y1,x2,y2;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
            if(y1>y2)
                cout<<"down\n";
            else if(y1<y2)
                cout<<"up\n";
            else
                cout<<"sad\n";
        }
        else if(y1==y2)
        {
            if(x1>x2)
                cout<<"left\n";
            else if(x1<x2)
                cout<<"right\n";
            else
                cout<<"sad\n";
        }
        else
            cout<<"sad\n";
    }
    return 0;
}
