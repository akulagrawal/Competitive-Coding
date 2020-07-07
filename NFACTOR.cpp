#include<bits/stdc++.h>

using namespace std;

int BIT[15][1000006];

void update(int i,int x)
{
    for(;x<=1000000;x+=x&-x)
        BIT[i][x]+=1;
}

int query(int n,int x)
{
    int sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT[n][x];
    return sum;
}

int prime[1000006];

void sieve(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!prime[i])
        {
            for(int j=2*i;j<=n;j+=i)
                prime[j]++;
            prime[i]=1;
        }
    }
}

int main()
{
    int t,a,b,n,ans,i;
    scanf("%d",&t);
    sieve(1000000);
    for(i=1;i<=1000000;i++)
    {
        if(prime[i]<=10)
            update(prime[i],i);
    }
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&n);

        printf("%d\n",query(n,b)-query(n,a-1));
    }
    return 0;
}
