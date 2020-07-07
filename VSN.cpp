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

long double x[5],y[5],z[5];

long double dist(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

long double crossmod(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2)
{
    long double a=y1*z2-y2*z1;
    long double b=z1*x2-z2*x1;
    long double c=x1*y2-x2*y1;
    return dist(a,b,c,0,0,0);
}

long double dist2(long double x1, long double y1, long double z1)
{
    long double a=crossmod(x[0]-x[3],y[0]-y[3],z[0]-z[3],x1-x[0],y1-y[0],z1-z[0]);
    long double b=dist(x[0],y[0],z[0],x1,y1,z1);
    return a/b;
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int i;
        for(i=0;i<4;i++)
            cin>>x[i]>>y[i]>>z[i];
        long double ra;
        cin>>ra;
        long double l=0.0, r=mod,mid;
        while(r-l>0.00000001)
        {
            mid=l+(r-l)/(2.0);
            if(dist2(x[1]+x[2]*mid,y[1]+y[2]*mid,z[1]+z[2]*mid)>ra)
                r=mid;
            else
                l=mid;
        }
        cout<<fixed<<setprecision(8)<<mid<<endl;
    }

    return 0;
}
