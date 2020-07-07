#include<bits/stdc++.h>

using namespace std;
#define PI 3.14159265359

int main()
{
    //freopen("progress_pie.txt","r",stdin);
    //freopen("AKUL2.txt","w",stdout);
    int t,i;
    double x1,y1,p;
    double dist,tan1,tan2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf",&p,&x1,&y1);
        printf("Case #%d: ",i);
        x1-=50;
        y1-=50;
        dist=(double)sqrt((x1*x1)+(y1*y1));
        if(dist>50||p==0)
            printf("white\n");
        else if(p==100)
            printf("black\n");
        else if(p==50)
        {
            if(x1>=0)
                printf("black\n");
            else
                printf("white\n");
        }
        else if(x1==0)
        {
            if(p>=50&&y1<=0)
                printf("black\n");
            else
                printf("white\n");
        }
        else
        {
            tan1=cos(p*2*PI/100)/sin(p*2*PI/100);
            tan2=(y1/x1);
            if(p>50)
            {
                if(x1>0)
                    printf("black\n");
                else if(tan2>=tan1)
                    printf("black\n");
                else
                    printf("white\n");
            }
            else
            {
                if(x1<0)
                    printf("white\n");
                else if(tan2>=tan1)
                    printf("black\n");
                else
                    printf("white\n");
            }
        }
    }
    return 0;
}
