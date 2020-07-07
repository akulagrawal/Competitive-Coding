#include<bits/stdc++.h>

using namespace std;

void SimpleSieve(int limit, vector<int> &prime,long m)
{
    bool mark[limit+1];
    memset(mark,1,sizeof(mark));
    for(int p=2;p*p<limit;p++)
    {
        if(mark[p]==1)
        {
            for(int i=p*2;i<limit;i+=p)
                mark[i]=0;
        }
    }
    for(int p=2;p<limit;p++)
    {
        if(mark[p]==1)
        {
            prime.push_back(p);
            if(p>=m)
                printf("%d\n",p);
        }
    }
}

void SegSieve(long m,long n)
{
    int limit=floor(sqrt(n))+1;
    vector<int> prime;
    SimpleSieve(limit,prime,m);
    long temp=(long)max((int)m,limit),low=temp,high=temp+limit;
    while(low<=n)
    {
        bool mark[limit+1];
        memset(mark,1,sizeof(mark));
        for(int i=0;i<prime.size();i++)
        {
            long loLim=(long)floor(low/prime[i]);
            loLim*=(long)prime[i];
            if(loLim<low)
                loLim+=prime[i];
            for(int j=0;j<=(int)(high-loLim);j+=prime[i])
                mark[j-low+loLim]=0;
        }
        for(int i=0;i<=(int)(high-low);i++)
        {
            long t=low+(long)i;
            if(mark[i]==1&&i>=(m-low)&&i<=(n-low))
                printf("%ld\n",t);
        }
        if(high==n)
            break;
        low+=limit+1;
        high+=limit+1;
        if(high>n)
            high=n;
    }
}

int main()
{
    int t;
    long m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld%ld",&m,&n);
        SegSieve(m,n);
    }
    return 0;
}
