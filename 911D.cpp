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

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    ll ans=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
                ans++;
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int p=(r-l+1)/2;
        ans=(ans+p)%2;
        if(ans%2)
            cout<<"odd\n";
        else
            cout<<"even\n";
    }
    return 0;
}
