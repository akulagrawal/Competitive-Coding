#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 300005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

queue<int> q;
int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,t;
    ll m,sum=0,maxm=0;
    scanf("%d%lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    q.push(a[0]);
    sum=(ll)a[0];
    i=1;
    while(!q.empty())
    {
        if(sum>m)
        {
            t=q.front();
            q.pop();
            sum-=(ll)t;
        }
        else
        {
            maxm=max(maxm,sum);
            if(i>=n)
                break;
            q.push(a[i]);
            sum+=(ll)a[i];

            i++;
        }
    }
    printf("%lld",maxm);
    return 0;
}
