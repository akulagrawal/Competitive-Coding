#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 10005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>
#define PI 3.14159265359

double r[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int t,n,f,i,m;
    double sum,low,mid,high;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&n,&f);
        f++;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&r[i]);
            r[i]*=r[i]*PI;
            sum+=r[i];
        }
        low=0;
        high=sum;
        while(high-low>0.00001)
        {
            mid=low+(high-low)/2;
            m=0;
            if(mid==0)
                m=f+1;
            else
            {
                for(i=0;i<n;i++)
                {
                    m+=r[i]/mid;
                    if(m>=f)
                        break;
                }
            }
            if(m>=f)
                low=mid;
            else
                high=mid-0.00001;
        }
        mid=low+(high-low)/2;
        printf("%lf\n",mid);
    }
    return 0;
}
