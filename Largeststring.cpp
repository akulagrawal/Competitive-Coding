#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,m,i,j=0,p=0,t=0;
    char a[500005],b[500005],maxm='A';
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='J')
        {
            b[j]=a[i];
            j++;
            m=m-i+p;
            maxm='A';
            t=i+1;
            p=i+1;
        }
        else if(a[i]>maxm)
        {
            maxm=a[i];
            t=i;
        }
        if(m<=0&&i==n-m)
            break;
        else if(i>=m+p)
        {
            b[j]=maxm;
            j++;
            i=t;
            m=m-i+p;
            p=i+1;
            maxm='A';
        }
    }
    b[n-m]='\0';
    printf("%s",b);
    return 0;
}


// above gave tle and below not tested


#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int b[10],n,m,p,i,j,k=0,f=0;
    char a[500005],c[500005];
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    for(i=0;i<10;i++)
        b[i]=0;
    for(i=0;i<n;i++)
    {
        p=a[i]-'A';
        b[p]++;
    }
    for(i=8;i>=0;i--)
    {
        b[i]+=b[i+1];
    }
    for(i=9;i>=0;i--)
    {
        if(b[i]>=(n-m))
        {
            p=b[i]-n+m;
            for(j=0;j<n;j++)
            {
                if(k<p&&((a[j]-'A')>i))
                {
                    c[f]=a[j];
                    f++;
                }
                else if(k>=p&&((a[j]-'A')>=i))
                {
                    c[f]=a[j];
                    f++;
                }
                else if((a[j]-'A')==i)
                    k++;
            }
            break;
        }
    }
    c[n-m]='\0';
    printf("%s",c);
    return 0;
}
