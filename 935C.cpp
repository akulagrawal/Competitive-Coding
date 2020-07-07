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
#define double long double

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(10)<<fixed;
    double r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double a,b,c;
    c=(r+dist(x1,y1,x2,y2))/2;
    if(c>r)
    {
        cout<<x1<<" "<<y1<<" "<<r;
        return 0;
    }
    if(x1==x2)
    {
        a=x1;
        if(y1>y2)
            b=y2+c;
        else
            b=y2-c;
    }
    else
    {
        double m=(y2-y1)/(x2-x1);
        double t=1.0/sqrt(m*m+1.0);
        if(x2>x1)
            t=-1*t;
        double q=m*t;
        a=x2+c*t;
        b=y2+c*q;
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}
