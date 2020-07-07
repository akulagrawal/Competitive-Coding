#include<bits/stdc++.h>

using namespace std;

int a[1000006];
vector<int> prime;

void SimpleSieve(int limit)
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
            prime.push_back(p);
    }
}

void sieve()
{
    int p;
    for(int i=0;i<prime.size();i++)
    {
        p=prime[i];
        p=p*p*p;
        for(int j=p;j<1000001;j+=p)
            a[j]=-1;
    }
}

int main()
{
    int t,n,p=1;
    SimpleSieve(101);
    sieve();
    for(int i=1;i<1000001;i++)
    {
        if(!a[i])
        {
            a[i]=p;
            p++;
        }
    }
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case %d: ",i);
        if(a[n]==-1)
            printf("Not Cube Free\n");
        else
            printf("%d\n",a[n]);
    }
    return 0;
}
