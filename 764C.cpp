#include<bits/stdc++.h>

using namespace std;

int c[100005],x[200005],y[200005];

vector<int> d[100005];

int main()
{
    int i,n,u,v,j,p=0,ans=1,z=0,a,b;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        d[u].push_back(v);
        d[v].push_back(u);
    }
    for(i=1;i<=n;i++)
        cin>>c[i];
    for(i=1;i<=n;i++)
    {
        for(j=0;j<d[i].size();j++)
        {
            if(c[d[i][j]]!=c[i])
            {
                x[z]=i;
                y[z]=d[i][j];
                z++;
             //d[i].erase(d[i].begin()+j+1);
            }
        }
    }
    a=x[0];
    b=y[0];
    for(i=1;i<z;i++)
    {
        if(x[i]!=a&&y[i]!=a)
        {
            p=1;
            break;
        }
    }
    if(p==0&&a!=0)
    {
        cout<<"YES\n"<<a;
        return 0;
    }
    for(i=1;i<z;i++)
    {
        if(x[i]!=b&&y[i]!=b)
        {
            cout<<"NO";
            return 0;
        }
    }
    if(!b)
        b=1;
    cout<<"YES\n"<<b;
    return 0;
}
