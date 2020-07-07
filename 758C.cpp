#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long m,n,k,x,y,s,minm,maxm,q,p,x1,y1;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&k,&x,&y);
    if(n>2)
    {
        s=(m*n)+(n-2)*m;
        minm=k/s;
        maxm=2*minm;
        if(x!=1&&x!=n)
            q=maxm;
        else
            q=minm;
        p=k%s;
        if(k%s>(m*n))
        {
            x1=(p-(m*n))/m;
            x1=n-x1;
            y1=(p-(m*n))%m;
            if(y1)
                x1--;
            else
                y1=m;
            if((x==x1&&y>y1)||(x<x1))
                q++;
            else
            {
                if(x==n)
                    q++;
                else
                    q+=2;
            }
            minm++;
            maxm+=2;
        }
        else if(k%s==(m*n))
        {
            q++;
            minm++;
            maxm++;
        }
        else
        {
            x1=p/m;
            y1=p%m;
            if(y1)
                x1++;
            else
                y1=m;
            if((x==x1&&y<=y1)||(x<x1))
                q++;
            if(k%s>m||k<=m)
                maxm++;
        }
    }
    else
    {
        s=m*n;
        minm=k/s;
        q=minm;
        if(x==1&&k%s>=y)
            q++;
        else if(x==2&&(k%s>=(m+y)))
            q++;
        if(k%s>0)
            maxm=minm+1;
        else
            maxm=minm;
    }
    printf("%I64d %I64d %I64d",maxm,minm,q);
    return 0;
}
