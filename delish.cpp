#include<bits/stdc++.h>
using namespace std;
long long a[10005],maxl[10005],minl[10005],maxr[10005],minr[10005];
int n;
void maxleft()
{
   long long currmax=a[0];
   int i;
   for(i=0;i<n;i++)
      maxl[i]=0;
      maxl[0]=a[0];
   for(i=1;i<n;i++)
   {
      currmax=max(a[i],currmax+a[i]);
       maxl[i]=max(maxl[i-1],currmax);
   }
}
void minleft()
{
    long long currmin=a[0];
    int i;
    for(i=0;i<n;i++)
        minl[i]=0;
        minl[0]=a[0];
    for(i=1;i<n;i++)
    {
       currmin=min(a[i],currmin+a[i]);
        minl[i]=min(minl[i-1],currmin);
    }
}
void maxright()
{
    long long currmax=a[n-1];
    int i;
    for(i=0;i<n;i++)
        maxr[i]=0;
        maxr[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)
    {
       currmax=max(a[i],currmax+a[i]);
        maxr[i]=max(maxr[i+1],currmax);
    }
}
void minright()
{
    long long currmin=a[n-1];
    int i;
    for(i=n-1;i>=0;i--)
        minr[i]=0;
        minr[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)
    {
            currmin=min(a[i],currmin+a[i]);
        minr[i]=min(minr[i+1],currmin);
    }
}

long long solve()
{
    maxleft();
    minleft();
    maxright();
    minright();
    int i;
    long long diff=abs(a[0]-a[1]);
    for(i=0;i<n-1;i++)
     {
       if(diff<=maxl[i]-minr[i+1])
           diff= maxl[i]-minr[i+1];

        if(diff<=maxr[i+1]-minl[i])
           diff=maxr[i+1]-minr[i];
     }
     return diff;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
         long long int ans=solve();
       // for(i=0;i<n;i++)
         //   cout<<maxl[i]<<" "<<minl[i]<<" "<<maxr[i]<<" "<<minr[i]<<endl;

         cout<<ans<<endl;
    }
    return 0;
}
