#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long fast_pow(int a,int n)
{
    long long result = (long long)1;
    long long power = (long long)n;
    long long value = (long long)a;
    while(power>0)
    {
        if(power&1)
        {
            result = (long long)(result*value);
            result = (long long)result%1000000007;
        }
        value = (long long)value*value;
        value = (long long)value%1000000007;
        power /= (long long)2;
    }
    return result;
}

long long arr[11][1003];

int main()
{
    int t,n,k;
    long long ans,temp,j=1,t1,t2;
    for(int i=1;i<=10;i++)
    {
        arr[i][1]=0;
        arr[i][2]=i;
        for(int k=3;k<=1000;k++)
        {
            t1=fast_pow(i,k-2);
            t2=arr[i][k-2];
            while(t1<t2)
            {
                t1+=MOD;
            }
            arr[i][k]=(((t1-t2)*(j-1))%MOD+(arr[i][k-2]*j)%MOD)%MOD;
        }
        j++;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%lld\n",arr[k][n]);
    }
    return 0;
}
