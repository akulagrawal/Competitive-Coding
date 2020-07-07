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

ll a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>a[i];
    sort(a,a+n);
    int ans=0;
    int j=0;
    i=0;
    while(j<n)
    {
    	while(a[j]<=a[i]&&j<n)
            j++;
        if(j>=n)
            break;
        ans++;
        i++;
        j++;
    }
    cout<<ans;


    return 0;
}