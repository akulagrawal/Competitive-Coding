#include<bits/stdc++.h>

using namespace std;

int x[11],y[11],p[11];

int main()
{
    int i,k=0;
    for(i=0;i<3;i++)
        scanf("%d%d",&x[i],&y[i]);
    x[3]=x[2]+x[1]-x[0];
    y[3]=y[2]+y[1]-y[0];
    x[4]=x[2]-x[1]+x[0];
    y[4]=y[2]-y[1]+y[0];
    x[5]=x[0]+x[2]-x[1];
    y[5]=y[0]+y[2]-y[1];
    x[6]=x[0]-x[2]+x[1];
    y[6]=y[0]-y[2]+y[1];
    x[7]=x[1]+x[0]-x[2];
    y[7]=y[1]+y[0]-y[2];
    x[8]=x[1]-x[0]+x[2];
    y[8]=y[1]-y[0]+y[2];
    for(i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(x[i]==x[j]&&y[i]==y[j])
            {
                p[j]=1;
            }
        }
    }
    for(i=3;i<9;i++)
    {
        if(!p[i])
            k++;
    }
    printf("%d\n",k);
    for(i=3;i<9;i++)
    {
        if(!p[i])
            printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}
