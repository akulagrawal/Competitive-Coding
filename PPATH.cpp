#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;

vector<int> v[10004];
int t,a,b,primeno[10004],sum,cost[10004];
bool prime[10004];
bool vis[10004];
//dijkstras algorithm
struct cmp
{
  bool operator()(const int &lhs, const int &rhs) const
  {
    return cost[lhs] > cost[rhs];
  }
};
void bfs(int n)
{
    int u;
    priority_queue<int,vector<int>, cmp> q;
    q.push(n);
    cost[n]=0;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        vis[u]=1;
        //cout<<u<<endl;
        if(u==b)
            break;
            //sum++;
        for(int i=0;i<v[u].size();i++)
        {
            if(!vis[v[u][i]])
                {
                    cost[v[u][i]] = min( cost[v[u][i]] ,cost[u] + 1);
                    q.push(v[u][i]);
                }
        }
    }
}

int main()
{
    int i,j=0,n,p;
    scanf("%d",&t);

    n=9999;
    for(p=2;p*p<=n;p++)
    {
        if(!prime[p])
        {
            for(i=p*2;i<=n;i+=p)
                prime[i]=1;
        }
    }
    for(i=1000;i<10000;i++)
    {
        if(!prime[i])
        {
            primeno[j]=i;
            j++;
        }
    }
    n=j;

    int x[4],y[4],temp1,temp2;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp1=primeno[i]; temp2=primeno[j];
            int k=0;
            while(temp1)
            {
                x[k]=temp1%10;
                k++;
                temp1=temp1/10;
            }
            k=0;
            while(temp2)
            {
                y[k]=temp2%10;
                k++;
                temp2=temp2/10;
            }
            int c=0;
            for(k=0;k<4;k++)
                if(x[k]!=y[k])
                    c++;
            if(c==1)
            {
               // cout<<primeno[i]<<" "<<primeno[j]<<endl;
                v[primeno[i]].push_back(primeno[j]);
                v[primeno[j]].push_back(primeno[i]);
            }
        }
    }
    while(t--)
    {
        scanf("%d%d",&a,&b);
        for(i=1000;i<10000;i++)
            { vis[i]=0; cost[i]=inf;}
        bfs(a);
        if(vis[b]==1)
            printf("%d\n",cost[b]);
        else
            printf("Impossible\n");
        sum=0;
    }
    return 0;
}
