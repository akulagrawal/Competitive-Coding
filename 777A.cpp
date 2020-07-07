#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    long n;
    int x,p;
    cin>>n>>x;
    p=n%6;
    if(x==1)
    {
        if(p==2||p==5)
            cout<<"2";
        else if(p==1||p==4)
            cout<<"0";
        else
            cout<<"1";
    }
    else if(x==0)
    {
        if(p==3||p==4)
            cout<<"2";
        else if(p==5||p==0)
            cout<<"0";
        else
            cout<<"1";
    }
    else
    {
        if(p==1||p==0)
            cout<<"2";
        else if(p==2||p==3)
            cout<<"0";
        else
            cout<<"1";
    }
    return 0;
}
