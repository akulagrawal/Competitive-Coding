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

int a[MAX],b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k,i;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]]=1;
        }
        for(i=0;;i++)
        {
            if(!b[i]&&!k)
                break;
            if(!b[i])
                k--;
        }
        cout<<i<<endl;
    }
    return 0;
}
