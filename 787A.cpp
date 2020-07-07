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
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,sum1,sum2,r=0,f=0;
    cin>>a>>b>>c>>d;
    sum1=b;
    sum2=d;
    while(sum1!=sum2)
    {
        if(r>10000||f>10000)
            break;
        //cout<<r<<" "<<f<<"\n";
        if(sum1>sum2)
        {
            sum2+=c;
            r++;
        }
        else
        {
            sum1+=a;
            f++;
        }
    }
    if(sum2!=sum1)
        cout<<"-1";
    else
        cout<<sum1;
    return 0;
}
