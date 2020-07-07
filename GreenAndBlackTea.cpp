#include<bits/stdc++.h>

using namespace std;
char s[100005];

int main()
{
    int n,k,a,b,j=0,i,p;
    scanf("%d%d%d%d",&n,&k,&a,&b);
    if(a>b)
        p=1;
    else
        p=0;
    while(a&&b)
    {
        if(a>b)
        {
            if(p==0)
            {
                s[j]='B';
                j++;
                b--;
            }
            if(a<k)
            {
                k=a;
                a=0;
            }
            else
                a-=k;
            for(i=0;i<k;i++)
            {
                s[j]='G';
                j++;
            }
            p=0;
        }
        else
        {
            if(p==1)
            {
                s[j]='G';
                j++;
                a--;
            }
            if(b<k)
            {
                k=b;
                b=0;
            }
            else
                b-=k;
            for(i=0;i<k;i++)
            {
                s[j]='B';
                j++;
            }
            p=1;
        }
    }
    if(a>0&&a<=k)
    {
        if(j==0||s[j-1]=='B')
        {
            for(i=0;i<a;i++)
            {
                s[j]='G';
                j++;
            }
        }
        else
            p=-1;
    }
    else if(b>0&&b<=k)
    {
        if(j==0||s[j-1]=='G')
        {
            for(i=0;i<b;i++)
            {
                s[j]='B';
                j++;
            }
        }
        else
            p=-1;
    }
    else if(a>0||b>0)
        p=-1;

    if(p==-1)
        printf("NO\n");
    else
    {
        for(i=0;i<n;i++)
            cout<<s[i];
    }
    return 0;
}
