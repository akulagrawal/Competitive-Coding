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

int p[10]={9,8,7,6,5,4,3,2,1,0};

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    int c=b%10;
    if(b-a>=5)
        cout<<"0";
    else
    {
        int i;
        for(i=0;i<10;i++)
            if(p[i]==c)
                break;
        a++;
        while(a!=b)
        {
            i=(i+1)%10;
            c=c*p[i];
            a++;
        }
        cout<<c%10;
    }
    return 0;
}
