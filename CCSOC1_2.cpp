#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

char a[MAX],b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j=0,ans=0,ans2=0;
    cin>>n;
    cin>>a>>b;
    sort(a,a+n);
    sort(b,b+n);
    i=0;
    while(j<n&&i<n)
    {
        while(b[j]<=a[i]&&j<n)
            j++;
        i++;
        if(j<n)
            ans++;
        j++;
    }
    i=0;
    j=0;
    while(j<n&&i<n)
    {
        while(b[j]<a[i]&&j<n)
            j++;
        i++;
        if(j<n)
            ans2++;
        j++;
    }
    cout<<n-ans2<<endl<<ans;
    return 0;
}
