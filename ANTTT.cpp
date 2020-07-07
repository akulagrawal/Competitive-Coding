#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

double ax[MAX],bx[MAX],ay[MAX],by[MAX];
int p,vis[MAX];
vector<int>v[MAX];

void dfs(int n)
{
    vis[n]=p;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])
            dfs(v[n][i]);
    }
}

int main()
{
    int t,n,m,i,x,y,j;
    double a1,a2,b11,b12,b21,b22;
    scanf("%d",&t);
    while(t--)
    {
        p=1;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&ax[i],&ay[i],&bx[i],&by[i]);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(min(ax[i],bx[i])>max(ax[j],bx[j]))
                    continue;
                else if(min(ax[j],bx[j])>max(ax[i],bx[i]))
                    continue;
                else if(min(ay[i],by[i])>max(ay[j],by[j]))
                    continue;
                else if(min(ay[j],by[j])>max(ay[i],by[i]))
                    continue;
                a1=max(min(ax[i],bx[i]),min(ax[j],bx[j]));
                a2=min(max(ax[i],bx[i]),max(ax[j],bx[j]));
                b11=((by[i]-ay[i])/(bx[i]-ax[i]))*(a1-ax[i])+ay[i];
                b12=((by[j]-ay[j])/(bx[j]-ax[j]))*(a1-ax[j])+ay[j];
                b21=((by[i]-ay[i])/(bx[i]-ax[i]))*(a2-ax[i])+ay[i];
                b22=((by[j]-ay[j])/(bx[j]-ax[j]))*(a2-ax[j])+ay[j];
                if(bx[i]==ax[i])
                {
                    b11=ay[i];
                    b21=by[i];
                }
                if(bx[j]==ax[j])
                {
                    b12=ay[j];
                    b22=by[j];
                }
                if(bx[i]==ax[i]&&bx[j]==ax[j])
                {
                    if(bx[i]==bx[j])
                    {
                        if((b11-b12)*(b21-b12)<=0)
                        {
                            v[i+1].pb(j+1);
                            v[j+1].pb(i+1);
                        }
                        else if((b11-b22)*(b21-b22)<=0)
                        {
                            v[i+1].pb(j+1);
                            v[j+1].pb(i+1);
                        }
                        else if((b11-b12)*(b11-b22)>0)
                        {
                            v[i+1].pb(j+1);
                            v[j+1].pb(i+1);
                        }
                    }
                }
                else if((b11-b12)*(b21-b22)<=0&&(by[i]!=ay[i]||by[j]!=ay[j]))
                {
                    v[i+1].pb(j+1);
                    v[j+1].pb(i+1);
                }
                else if(by[i]==ay[i]&&by[j]==ay[j]&&by[i]==by[j])
                {
                    b11=ax[i];
                    b21=bx[i];
                    b12=ax[j];
                    b22=bx[j];
                    if((b11-b12)*(b21-b12)<=0)
                    {
                        v[i+1].pb(j+1);
                        v[j+1].pb(i+1);
                    }
                    else if((b11-b22)*(b21-b22)<=0)
                    {
                        v[i+1].pb(j+1);
                        v[j+1].pb(i+1);
                    }
                    else if((b11-b12)*(b11-b22)>0)
                    {
                        v[i+1].pb(j+1);
                        v[j+1].pb(i+1);
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                p++;
            }
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            if(vis[x]==vis[y])
                printf("YES\n");
            else
                printf("NO\n");
        }
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            vis[i]=0;
        }
    }
    return 0;
}
