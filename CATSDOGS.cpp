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
    ll c,d,l;
    cin>>t;
    while(t--)
    {
    	cin>>c>>d>>l;
    	if((l%4)||(l<((d+max((ll)0,c-2*d))*4))||(l>((c+d)*4)))
    		cout<<"no\n";
    	else
    		cout<<"yes\n";
    }


    return 0;
}