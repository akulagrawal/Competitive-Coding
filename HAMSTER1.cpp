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
    int t,k1,k2,v;
    double theta,a,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&v,&k1,&k2);
        if(!k1)
            theta=acos(0);
        else
        {
            a=(double)(k2)/(4*(double)k1);
            theta=atan(a+sqrt((a*a)+1));
        }
        p=((2*k1*v*v*sin(theta)*cos(theta))+(k2*v*v*sin(theta)*sin(theta)/2))/10;
        printf("%.3lf %.3lf\n",theta,p);
    }
    return 0;
}
