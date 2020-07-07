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

struct cmp
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum;
    priority_queue< int, vector<int>, cmp> q;
    priority_queue< int, vector<int> > p;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>0)
        {
            sum++;
            if(p.size()<=q.size())
                p.push(n);
            else
                q.push(n);
        }
        else if(n<0)
        {
            while(p.size()<q.size())
            {
                p.push(q.top());
                q.pop();
            }
            printf("%d %d %d %d\n",p.size(),q.size(),p.top(),q.top());
            p.pop();
        }
        if(!n)
        {
            sum=0;
            while(!p.empty())
                p.pop();
            while(!q.empty())
                q.pop();
        }
    }
    return 0;
}
