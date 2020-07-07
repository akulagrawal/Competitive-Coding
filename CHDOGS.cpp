#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int t;
    double s,v,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&s,&v);
        ans=(2*s/(3*v));
        printf("%.20f\n",ans);
    }
    return 0;
}
