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

int r[55];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int t,l,i;
    ll p,low,mid,high,d,sum;
    double c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d",&p,&l);
        for(i=0;i<l;i++)
            scanf("%d",&r[i]);
        low=0;
        high=((ll)r[0])*(p*(p+1))/2;
        while(low<high)
        {
            sum=0;
            mid=low+(high-low)/2;
            for(i=0;i<l;i++)
            {
                c=(double)mid/(double)r[i];
                d=(sqrt(1+(8*c))-1)/2;
                sum+=d;
                //cout<<d<<" ";
            }
            //cout<<mid<<"\n";
            if(sum<p)
                low=mid+1;
            else
                high=mid;
        }
        mid=low+(high-low)/2;
        printf("%lld\n",mid);
    }
    return 0;
}
