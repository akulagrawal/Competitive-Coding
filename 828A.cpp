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

int t[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b,i,p1=0,p2=0,p3=0;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
        cin>>t[i];
    for(i=0;i<n;i++)
    {
        if(t[i]==1)
        {
            if(a>0)
                a--;
            else if(b>0)
            {
                p1++;
                b--;
            }
            else if(p1>0)
                p1--;
            else
                p3++;
        }
        else
        {
            if(b>0)
                b--;
            else
                p2++;
        }
    }
    cout<<p3+(2*p2);
    return 0;
}
