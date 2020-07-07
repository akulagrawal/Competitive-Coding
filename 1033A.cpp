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
    
    int n;
    cin>>n;
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;

    if(bx==ax||by==ay||(bx-ax)==(by-ay))
    {
    	cout<<"NO";
    	return 0;
    }

    if(((bx-ax)*(cx-ax)<=0)||((by-ay)*(cy-ay)<=0))
    {
    	cout<<"NO";
    	return 0;
    }

    cout<<"YES";


    return 0;
}