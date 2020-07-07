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

int g[105][105],r[105],c[105];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,minm,ans=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>g[i][j];
    }
    if(m<n)
    {
        for(j=0;j<m;j++)
        {
            minm=g[0][j];
            for(i=0;i<n;i++)
                minm=min(minm,g[i][j]);
            for(i=0;i<n;i++)
                g[i][j]-=minm;
            c[j]=minm;
            ans+=minm;
        }
        for(i=0;i<n;i++)
        {
            minm=g[i][0];
            for(j=0;j<m;j++)
                minm=min(minm,g[i][j]);
            for(j=0;j<m;j++)
                g[i][j]-=minm;
            r[i]=minm;
            ans+=minm;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            minm=g[i][0];
            for(j=0;j<m;j++)
                minm=min(minm,g[i][j]);
            for(j=0;j<m;j++)
                g[i][j]-=minm;
            c[i]=minm;
            ans+=minm;
        }
        for(j=0;j<m;j++)
        {
            minm=g[0][j];
            for(i=0;i<n;i++)
                minm=min(minm,g[i][j]);
            for(i=0;i<n;i++)
                g[i][j]-=minm;
            r[j]=minm;
            ans+=minm;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(g[i][j])
            {
                cout<<-1;
                return 0;
            }
    }
    cout<<ans<<endl;
    if(m<n)
    {
        for(i=0;i<n;i++)
        {
            while(r[i])
            {
                cout<<"row "<<i+1<<endl;
                r[i]--;
            }
        }
        for(j=0;j<m;j++)
        {
            while(c[j])
            {
                cout<<"col "<<j+1<<endl;
                c[j]--;
            }
        }
    }
    else
    {
        for(j=0;j<m;j++)
        {
            while(r[j])
            {
                cout<<"col "<<j+1<<endl;
                r[j]--;
            }
        }
        for(i=0;i<n;i++)
        {
            while(c[i])
            {
                cout<<"row "<<i+1<<endl;
                c[i]--;
            }
        }
    }
    return 0;
}
