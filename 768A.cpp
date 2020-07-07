#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

long a[MAX],minm,maxm;

int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    minm=a[0];
    maxm=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>maxm)
            maxm=a[i];
        if(a[i]<minm)
            minm=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>minm&&a[i]<maxm)
            ans++;
    }
    cout<<ans;
    return 0;
}
