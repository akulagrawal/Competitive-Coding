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
                cout<<p<<"\n";
        }
    }
}

void SegSieve(long m,long n)
{
    int limit=floor(sqrt(n))+1;
    vector<int> prime;
    SimpleSieve(limit,prime,m);
    long temp=max((int)m,limit),low=temp,high=temp+limit;
    while(low<=n)
    {
        bool mark[limit+1];
        memset(mark,1,sizeof(mark));
        for(int i=0;i<prime.size();i++)
        {
            int loLim=floor(low/prime[i])*prime[i];
            if(loLim<low)
                loLim+=prime[i];
            for(int j=loLim;j<=high;j+=prime[i])
                mark[j-low]=0;
        }
        for(int i=low;i<=high;i++)
        {
            if(mark[i-low]==1&&i>=m&&i<=n)
                printf("%d\n",i);
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
        printf("\n");
    }
    return 0;
}
