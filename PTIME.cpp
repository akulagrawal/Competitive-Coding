#include<bits/stdc++.h>

using namespace std;

int a[10004];
vector<int> prime;

int main()
{
    int n,p,t,sum,i,j;
    scanf("%d",&n);
    for(i=2;i*i<=n;i++)
    {
        if(!a[i])
        {
            for(j=2*i;j<=n;j+=i)
                a[j]=1;
        }
    }
    for(i=2;i<=n;i++)
    {
        if(!a[i])
            prime.push_back(i);
    }
    for(int i=0;i<prime.size();i++)
    {
        if(i)
            printf(" * ");
        sum=0;
        p=prime[i];
        t=log(n)/log(p);
        for(int j=1;j<=t;j++)
                sum+=n/pow(p,j);
        printf("%d^%d",p,sum);
    }
    return 0;
}
