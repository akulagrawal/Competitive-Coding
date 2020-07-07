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
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int q=min(a[n-1]-1,1000000-a[0]);
    for(i=0;i<n-1;i++)
        q=min(q,max(a[i]-1,1000000-a[i+1]));
    cout<<q;
    return 0;
}
