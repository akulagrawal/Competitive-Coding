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
#define pdd pair<double,double>

double x[MAX],y[MAX];
pair<double,int> z[MAX];
int ans[MAX];

double cross(int x1,int x2,int x3)
{
    return ((x[x1]-x[x2])*(y[x3]-y[x2])-(y[x1]-y[x2])*(x[x3]-x[x2]));
}

double distsq(double x1,double y1,double x2,double y2)
{
    return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool sortmod(const pair<double,int> &a,const pair<double,int> &b)
{
    if(a.f!=b.f)
        return (a.f < b.f);
    else
        return distsq(x[a.s],y[a.s],0.0,0.0)<=distsq(x[b.s],y[b.s],0.0,0.0);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,i,j,k;
    double xs,ys,p,dist;
    scanf("%d",&t);
    while(t--)
    {
        xs=MAX;
        ys=MAX;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        k=0;
        for(i=0;i<n;i++)
        {
            if((y[i]<ys)||(y[i]==ys&&x[i]<xs))
            {
                xs=x[i];
                ys=y[i];
                k=i;
            }
        }
        for(i=0;i<n;i++)
        {
            x[i]-=xs;
            y[i]-=ys;
            z[i]=mp(atan2(y[i],x[i]),i);
        }
        sort(z,z+n,sortmod);
        ans[0]=k;
        for(i=0;i<n;i++)
        {
            if(z[i].f||x[z[i].s])
                break;
        }
        j=0;
        for(;i<n;i++)
        {
            p=z[i].f;
            i++;
            while(z[i].f==p&&i<n)
                i++;
            i--;
            for(k=j;k>0;k--)
            {
                if(abs(cross(z[i].s,ans[k],ans[k-1])<=0.0))
                    j--;
                else
                {
                    j++;
                    ans[j]=z[i].s;
                    break;
                }
            }
            if(!j)
            {
                j++;
                ans[j]=z[i].s;
            }
        }
        dist=0;
        for(i=1;i<=j;i++)
            dist+=sqrt(distsq(x[ans[i]],y[ans[i]],x[ans[i-1]],y[ans[i-1]]));
        dist+=sqrt(distsq(x[ans[j]],y[ans[j]],x[ans[0]],y[ans[0]]));
        printf("%lf\n",dist);
        for(i=0;i<=j;i++)
            printf("%d ",ans[i]+1);
        printf("\n");
    }
    return 0;
}
