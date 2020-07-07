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

long double fast_pow(long double a,int n)
{
    long double result = 1;
    long long power = n;
    long double value = a;
    while(power>0)
    {
        if(power&1)
            result = result*value;
        value = value*value;
        power /= 2;
    }
    return result;
}

int main()
{
    int t,i;
    ll n,ans,a,b,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("INFINITY\n");
            continue;
        }
        ans=0;
        for(i=2;i<=40;i++)
        {
            a=pow((long double)n,double(1.0/(i-1)));
            temp=fast_pow(a+1,i-1);
            if(temp<=n)
                a++;
            b=ceil(pow((long double)((n+1)/2.0),double(1.0/(i-1))));
            temp=fast_pow(b-1,i-1);
            if(temp>=ceil((long double)((n+1)/2.0)))
                b--;
            if(a<=1)
                break;
            ans+=a-b+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
