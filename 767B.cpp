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

ll a[MAX];

int main()
{
    ll ts,tf,t;
    ll t1,t2,minm,ans;
    int n,i;
    cin>>ts>>tf>>t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]-1+t>tf)
            break;
        t1=ts+(i*t);
        if(a[i]>t1)
        {
            cout<<a[i]-1;
            return 0;
        }
    }
    t1=ts+(n*t);
    if(tf>=(t1+t))
    {
        cout<<t1;
        return 0;
    }
    minm=ts-a[0];
    ans=a[0]-1;
    for(i=1;i<n;i++)
    {
        if(a[i]-1+t>tf)
            break;
        t1=ts+(i*t);
        if(minm>(t1-a[i]))
        {
            minm=t1-a[i];
            ans=a[i]-1;
        }
    }
    t1=ts+(i*t);
    if(minm>(t1-a[i-1]-2)&&tf>=a[i-1]+1+t)
    {
        cout<<tf-t;
        return 0;
    }
    cout<<ans;
    return 0;
}
