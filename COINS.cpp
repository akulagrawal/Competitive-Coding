#include<bits/stdc++.h>

using namespace std;
long long doll[100005];

long long dol(long long n)
{
    long long a,b,c;
    a=n/2;
    b=n/3;
    c=n/4;
    if(n==0)
        return 0;
    else if(n<=100000)
        return doll[n];
    else
        return max(dol(a)+dol(b)+dol(c),n);
}

int main()
{
    long long n;
    int a,b,c,t=0,sum;
    doll[0]=0;
    for(int i=1;i<100001;i++)
    {
        a=i/2;
        b=i/3;
        c=i/4;
        sum=doll[a]+doll[b]+doll[c];
        doll[i]=max(sum,i);
    }
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",dol(n));
        t++;
        if(t==10)
            break;
    }
    return 0;
}
