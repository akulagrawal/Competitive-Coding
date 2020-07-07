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

struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};

priority_queue< int , vector<int> , compare > p;
priority_queue< int , vector<int> > q;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        while(1)
        {
            scanf("%d",&n);
            if(!n)
                break;
            if(n>0)
            {
                if(p.size()>=q.size())
                {
                    p.push(n);
                    q.push(p.top());
                    p.pop();
                }
                else
                {
                    q.push(n);
                    p.push(q.top());
                    q.pop();
                }
            }
            else
            {
                printf("%d\n",q.top());
                q.pop();
                if(p.size()>q.size())
                {
                    q.push(p.top());
                    p.pop();
                }
            }
        }
        while(!q.empty())
            q.pop();
        while(!p.empty())
            p.pop();
    }
    return 0;
}
