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

void build(int* a[],int b[],int node,int start,int end1)
{
    if(start==end1)
    {
        a[node]=&b[start];
        return;
    }
    int mid=start+(end1-start)/2;
    int *temp1=NULL, *temp2=NULL;
    build(a,b,2*node,start,mid);
    build(a,b,2*node+1,mid+1,end1);
    if(*a[2*node]<=*a[2*node+1])
        a[node]=a[2*node];
    else
        a[node]=a[2*node+1];
}

void add(int *a[],int c[],int node,int start,int end1,int pos)
{
    if(start==end1)
        a[node]=&c[start];
    else
    {
        int mid=start+(end1-start)/2;
        if(pos>=start&&pos<=mid)
            add(a,c,2*node,start,mid,pos);
        else
            add(a,c,2*node+1,mid+1,end1,pos);
        if(*a[2*node]<=*a[2*node+1])
            a[node]=a[2*node];
        else
            a[node]=a[2*node+1];
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int *a[MAX];
    int b[5][MAX];
    int c[MAX][5];
    int d[MAX];
    int k[MAX];
    int i,j,n=4,m=5;
    for(i=0;i<n;i++)
        k[i]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>b[i][j];
            c[j][i]=b[i][j];
        }
        c[j][i]=MAX;
    }
    build(a,c[0],1,0,n-1);
    i=0;
    while(1)
    {
        d[i]=*a[1];
        i++;
        for(j=0;j<n;j++)
        {
            if(&c[k[j]][j]==a[1])
            {
                k[j]++;
                add(a,c[k[j]],1,0,n-1,j);
                break;
            }
        }
        if(*a[1]==MAX)
            break;
    }
    for(i=0;i<(n*m);i++)
        cout<<d[i]<<" ";
    return 0;
}
