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
    int t;
    double p,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&p);
        if(p>=0.5)
            ans=((3*p)-(2*p*p))*10000;
        else
            ans=(p-(2*p*p)+1)*10000;
        printf("%lf\n",ans);
    }
    return 0;
}
