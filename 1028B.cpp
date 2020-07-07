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
    
    int n,m;
    cin>>n>>m;
    int x=n/9;
    x+=(bool)(n%9);
    string a,b;
    int i;
    for(i=0;i<x;i++)
    {
    	a.pb('9');
    	b.pb('0');
    }
    string c="9";
    c=c+b;
    c=c+a;
    string d=a+b;
    d[d.size()-1]='1';
    cout<<c<<" "<<d;





    return 0;
}