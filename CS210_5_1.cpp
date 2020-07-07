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

int findp(int a[],int l,int r,int &p)                   // find position of next element to be included in sorted array
{                                                       // by binary search
    int k=r;
    while(l<r)
    {
        p++;
        int mid=l+(r-l)/2;
        if(a[mid]<=a[k])
            l=mid+1;
        else
            r=mid;
    }
    return l;
}

int ins_sort(int a[],int n)                 // sort array a by insertion sort
{
    int i,j,pos,num,val=0;                  // val stores no. of comparisons in binary search
    for(i=0;i<n;i++)
    {
        pos=findp(a,0,i,val);
        num=a[i];
        for(j=i-1;j>=pos;j--)
            a[j+1]=a[j];
        a[pos]=num;
    }
    return val;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,val;
    cin>>n;
    int x[n+1];
    for(i=0;i<n;i++)
        cin>>x[i];
    val=ins_sort(x,n);
    cout<<val<<endl;
    for(i=0;i<n;i++)
        cout<<x[i]<<" ";
    return 0;
}
