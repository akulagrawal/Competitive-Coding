#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>


int id[MAX], nodes, edges;
pair <int, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

int kruskal(pair<int, pair<int, int> > p[])
{
    int x, y;
    int cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}


int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[MAX];
    int y,t,i,k,j;
    int weight, cost, minimumCost;
    cin>>t;
    while(t--)
    {
        edges=0;
        j=0;
        initialize();
        cin>>nodes;
        for(i=1;i<=nodes;i++)
        {
            cin>>s;
            cin>>k;
            edges+=k;
            while(k--)
            {
                cin>>y>>weight;
                p[j]=mp(weight,mp(i,y));
                j++;
            }
        }
        // Sort the edges in the ascending order
        sort(p, p + edges);
        minimumCost = kruskal(p);
        cout << minimumCost << endl;
    }
    return 0;
}
