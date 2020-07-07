#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t,n,i,p1,p2,c,d,p,ans;
    long long prod;
    char a[100005],b[100005];
    scanf("%d",&t);
    while(t--)
    {
        p1=0;p2=0;p=0;ans=0;prod=1;
        scanf("%s%s",a,b);
        n=strlen(a);
        for(i=0;i<(n-1);i++)
        {
            c=0;d=0;

            if(a[i]=='2')
                p1++;
            else if(i==0||a[i-1]=='1')
                p1=0;
            else
                c++;

            if(b[i]=='2')
                p2++;
            else if(i==0||b[i-1]=='1')
                p2=0;
            else
                d++;

            if(((c+d)==2&&p1!=2)||((c+d)==2&&p2!=2))
            {
                printf("0\n");
                p=1;
                break;
            }
            else if((c+d)==2)
            {
                p1=0;
                p2=0;
                continue;
            }
            else if(c==1)
            {
                if((p1<2&&p2==3)||(p1<2&&p2==1))
                {
                    a[i]='2';
                    b[i]='1';
                    p1++;
                    p2--;
                }
                else if(p1<2)
                {
                    printf("0\n");
                    p=1;
                    break;
                }
            }
            else if(d==1)
            {
                if((p2<2&&p1==3)||(p2<2&&p1==1))
                {
                    b[i]='2';
                    a[i]='1';
                    p2++;
                    p1--;
                }
                else if(p2<2)
                {
                    printf("0\n");
                    p=1;
                    break;
                }
            }
            else
            {
                if(p1>2&&p2==0)
                {
                    if((i==2)||(i>2&&b[i-3]=='1'))
                    {
                        a[i-2]='1';
                        a[i-1]='1';
                        b[i-2]='2';
                        b[i-1]='2';
                        p1-=2;
                        p2+=2;
                    }
                    else
                    {
                        a[i]='1';
                        b[i]='2';
                        p1--;
                        p2++;
                    }
                }
                else if(p2>2&&p1==0)
                {
                    if((i==2)||(i>2&&a[i-3]=='1'))
                    {
                        b[i-2]='1';
                        b[i-1]='1';
                        a[i-2]='2';
                        a[i-1]='2';
                        p2-=2;
                    }
                    else
                    {
                        b[i]='1';
                        a[i]='2';
                        p2--;
                        p1++;
                    }
                }
                else if(p1>2||p2>2)
                {
                    printf("0\n");
                    p=1;
                    break;
                }
            }

            if(a[i]=='1')
                p1=0;
            if(b[i]=='1')
                p2=0;

            if((i==(n-2))&&((p1+p2)!=0))
            {
                p=1;
                printf("0\n");
            }
        }
        if(p==0)
        {
            for(i=0;i<(n-1);i++)
            {
                if(a[i]==b[i])
                    ans++;
                else if((i<(n-1))&&(a[i]!=b[i])&&(a[i+1]!=b[i+1])&&(a[i]==a[i+1]))
                {
                    if(i==0)
                        ans++;
                    if(a[i]=='1')
                    {
                        if(a[i-1]=='1')
                            ans++;

                        i++;
                    }
                    else
                    {
                        if(b[i-1]=='1')
                            ans++;

                        i++;
                    }
                }
                else if((i<(n-2))&&(a[i+1]=='2')&&(b[i+1]=='2'))
                {
                    if(i==0)
                        ans++;
                    else if(a[i-1]=='1'&&b[i-1]=='1')
                        ans++;
                }
            }
            for(i=0;i<(ans+1);i++)
            {
                prod=(prod*2)%1000000007;
            }
            printf("%lld\n",prod);
        }
    }
    return 0;
}
