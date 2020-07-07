#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

int a[5]={0,1,-1,0,0};
int b[5]={0,0,0,1,-1};
int x[5],y[5],s[5];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,x1,y1,x2,y2,x3,y3,j,p=0;
    for(i=0;i<3;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            x1=x[j]+a[i];
            y1=y[j]+b[i];
            x2=x[(j+1)%3];
            y2=y[(j+1)%3];
            x3=x[(j+2)%3];
            y3=y[(j+2)%3];
            s[0]=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            s[1]=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
            s[2]=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
            if(!s[0]||!s[1]||!s[2])
                continue;
            for(int k=0;k<3;k++)
            {
                if(s[k]+s[(k+1)%3]==s[(k+2)%3])
                {
                    if(i==0)
                        p=1;
                    else
                        p=2;
                }
                if(p)
                    break;
            }
            if(p)
                break;
        }
        if(p)
            break;
    }
    if(p==1)
        printf("RIGHT");
    else if(p==2)
        printf("ALMOST");
    else
        printf("NEITHER");
    return 0;
}
