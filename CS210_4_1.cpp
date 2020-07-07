#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define mod 1000000007
#define ll long long

void swap2(ll &a,ll &b)                                 // swap 2 long long integers
{
    ll temp=a;
    a=b;
    b=temp;
}

int part(ll a[],int l,int r)                            // partition function for quick sort, returns the index of pivot
{
    int rc=r,lc=l;
    ll pivot=a[l];
    while(lc<=rc)
    {
        while((a[lc]<=pivot)&&lc<=rc)
            lc++;
        while((a[rc]>pivot)&&lc<=rc)
            rc--;
        if(lc<=rc)
            swap2(a[lc],a[rc]);
    }
    swap2(a[l],a[rc]);
    return rc;
}

void qsort1(ll a[],int l,int r)                                      // quick sort function
{
    if(l<r)
    {
        int x=part(a,l,r);
        qsort1(a,l,x-1);
        qsort1(a,x+1,r);
    }
}

int main()
{
    int n,i;
    cin>>n;
    ll a[n+1];
    for(i=0;i<n;i++)
        cin>>a[i];
    while(n--)
    {
        qsort1(a,0,n);
        for(i=0;i<n;i++)
            a[i]=a[i+1]-a[i];
    }
    cout<<a[0];
    return 0;
}
