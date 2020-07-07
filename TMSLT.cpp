#include<bits/stdc++.h>
#define MOD 1000000

using namespace std;

long long s[1000006];

int main()
{
    int t,n,j;
    long long a,b,c,d,sum;
    scanf("%d",&t);
    while(t--)
    {
        j=0;
        sum=0;
        scanf("%d",&n);
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        s[d]++;
        n--;
        while(n--)
        {
            d=((a*d*d)+(b*d)+c)%MOD;
            s[d]++;
        }
        for(int i=0;i<MOD;i++)
        {
            s[i]%=2;
            if(s[i])
            {
                if(j%2==0)
                    sum+=i;
                else
                    sum-=i;
                j++;
                s[i]=0;
            }
        }
        sum=abs(sum);
        printf("%lld\n",sum);
    }
    return 0;
}
