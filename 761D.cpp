#include<bits/stdc++.h>

using namespace std;

long long a[100005],b[100005],p[100005],t[100005];
int main()
{
    int n;
    long long l,r,maxm,minm;
    cin>>n>>l>>r;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        cin>>p[i];
        t[i]=p[i];
    }
    sort(t,t+n);
    for(i=0;i<n;i++)
    {
        if(t[i]!=i+1)
        {
            cout<<"-1";
            return 0;
        }
    }
    for(i=0;i<n;i++)
        b[i]=a[i]+p[i];
    maxm=minm=b[0];
    for(i=1;i<n;i++)
    {
        maxm=max(b[i],maxm);
        minm=min(b[i],minm);
    }
    if((maxm-minm)>(r-l))
        cout<<"-1";
    else
    {
        if(maxm>r)
        {
            for(i=0;i<n;i++)
                cout<<b[i]-maxm+r<<" ";
        }
        else if(minm<l)
        {
            for(i=0;i<n;i++)
                cout<<b[i]+l-minm<<" ";
        }
        else
        {
            for(i=0;i<n;i++)
                cout<<b[i]<<" ";
        }
    }
    return 0;
}
