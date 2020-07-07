#include<bits/stdc++.h>

using namespace std;

int a[55],b[55],x[105],y[105];

int main()
{
    int n,l,ans=0,p,i,j;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<n;i++)
    {
        x[i]=a[i]-a[i-1];
        y[i]=b[i]-b[i-1];
    }
    x[0]=l-a[n-1]+a[0];
    y[0]=l-b[n-1]+b[0];
    for(i=0;i<n;i++)
    {
        x[i+n]=x[i];
        y[i+n]=y[i];
    }
    for(i=0;i<n;i++)
    {
        p=0;
        for(j=i;j<n;j++)
        {
            if(x[j-i]==y[j])
                p++;
            else
                break;
        }
        if(p!=n-i)
            continue;
        else
        {
            for(j=0;j<i;j++)
            {
                if(x[j+n-i]==y[j+n])
                    p++;
                else
                    break;
            }
        }
        if(p==n)
        {
            ans=1;
            break;
        }
    }
    if(ans)
        printf("YES");
    else
        printf("NO");
    return 0;
}
