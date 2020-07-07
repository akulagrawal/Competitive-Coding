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

int a[104];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    if(n%2&&(a[0]%2)&&a[n-1]%2)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
