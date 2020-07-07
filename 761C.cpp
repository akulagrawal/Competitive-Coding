#include<bits/stdc++.h>

using namespace std;

char s[55][55];
int a[55],b[55],c[55];

int main()
{
    int n,m,i,j,k,minm;
    cin>>n>>m;
    minm=3*m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>s[i][j];
    }
    for(j=0;j<n;j++)
    {
        for(i=1;i<(m/2)+1;i++)
        {
            if((s[j][i]>='a'&&s[j][i]<='z')||(s[j][m-i]>='a'&&s[j][m-i]<='z'))
            {
                if(!a[j])
                    a[j]=i;
            }
            if((s[j][i]>='0'&&s[j][i]<='9')||(s[j][m-i]>='0'&&s[j][m-i]<='9'))
            {
                if(!b[j])
                    b[j]=i;
            }
            if((s[j][i]=='*'||s[j][i]=='#'||s[j][i]=='&')||(s[j][m-i]=='*'||s[j][m-i]=='#'||s[j][m-i]=='&'))
            {
                if(!c[j])
                    c[j]=i;
            }
        }
    }
    for(k=0;k<n;k++)
    {
        if(s[k][0]>='a'&&s[k][0]<='z')
        {
            a[k]=0;
            if(!b[k])
                b[k]=m;
            if(!c[k])
                c[k]=m;
        }
        else if(s[k][0]>='0'&&s[k][0]<='9')
        {
            b[k]=0;
            if(!a[k])
                a[k]=m;
            if(!c[k])
                c[k]=m;
        }
        else
        {
            c[k]=0;
            if(!a[k])
                a[k]=m;
            if(!b[k])
                b[k]=m;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(i!=j&&j!=k&&i!=k)
                {
                    if((minm>(a[i]+b[j]+c[k]))&&a[i]<m&&b[j]<m&&c[k]<m)
                        minm=a[i]+b[j]+c[k];
                }
            }
        }
    }
    cout<<minm;
    return 0;
}
