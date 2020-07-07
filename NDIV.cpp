#include<bits/stdc++.h>

using namespace std;

int s[10004];

int main()
{
    long a,b,p,t;
    int n,i,j,ans;
    scanf("%ld%ld%d",&a,&b,&n);
    for(i=2;i*i<=b;i++)
    {
        p=(long)((a-1)/i);
        p++;
        t=p;
        if(p<i)
        {
            p=i;
            t=i;
        }
        p*=(long)i;
        for(j=(p-a);j<=(b-a);j+=i)
        {
            if(t==i)
                s[j]++;
            else if(t>1)
                s[j]+=2;
            t++;
        }
    }
    ans=0;
    if(a==1)
        s[0]--;
    for(i=0;i<=(b-a);i++)
    {
        if(s[i]==(n-2))
            ans++;
    }
    printf("%d",ans);
    return 0;
}
