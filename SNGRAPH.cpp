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

pii a[MAX];
int b[MAX],c[MAX];
int Arr[MAX],size1[MAX];

bool cmp(const pii &a,const pii &c)
{
    return b[a.f]>b[c.f];
}

void initialize(int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size1[ i ] = 1;
    }
}

int root (int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
    return i;
}

void weightedunion(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size1[root_A] < size1[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size1[root_B] += size1[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size1[root_A] += size1[root_B];
    }
}

bool find1(int A,int B)
{
    if( root(A)==root(B) )
    return true;
    else
    return false;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,j,u,v,count1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        count1=1;
        memset(b,0,sizeof(b));
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
            a[i]=mp(u,v);
            b[u]++;
            b[v]++;
        }
        for(i=0;i<m;i++)
        {
            if(b[a[i].f]>b[a[i].s])
                a[i]=mp(a[i].s,a[i].f);
        }
        sort(a,a+m,cmp);
        initialize(n+1);
        j=0;
        for(i=n;i>0;i--)
        {
            while(b[a[j].f]==i&&j<m)
            {
                if(!find1(a[j].f,a[j].s))
                    count1++;
                weightedunion(a[j].f,a[j].s);
                j++;
            }
            c[i-1]=n-count1;
        }
        for(i=0;i<n;i++)
            cout<<c[i]<<" ";
    }
    return 0;
}
