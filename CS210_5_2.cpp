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

int merge2(int a[],int l,int mid,int r)             // function to merge two sorted arrays/ halves of an array from l to r
{                                                   // and return no. of inversions (x,y) where x is in 1st(lesser) half and y is in 2nd(greater) half
    int i=l,j=mid+1,k=0,sum=0;                      // sum stores this no. of inter half inversions
    int b[r-l+1];
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            sum+=mid-i+1;                           // since both halves are sorted, if some element of 2nd half is less that some element of 1st half
            b[k]=a[j];                              // it is less than all the rest elements of 1st half
            j++;
        }
        k++;
    }                                               // atleast one of 1st or 2nd half is used completely. So sum will not be changed after this
    for(;i<=mid;i++,k++)                            // including rest elements (if any) of 1st half in sorted array
        b[k]=a[i];
    for(;j<=r;j++,k++)
        b[k]=a[j];
    for(i=l;i<=r;i++)
        a[i]=b[i-l];
    return sum;
}

int merge_sort(int a[],int l,int r)                     // function to sort array and return no. of inversions
{
    if(l==r)
        return 0;
    int mid=l+(r-l)/2;
    int p1,p2,p3;
    p1=merge_sort(a,l,mid);                             // p1 has no. of inversions in with elements only in 1st half
    p2=merge_sort(a,mid+1,r);                           // p2 has no. of inversions in with elements only in 2nd half
    p3=merge2(a,l,mid,r);                               // p3 has no. of inversions between elements of both 1st half and 2nd half
    return (p1+p2+p3);                                  // for whole array, no. of inversions is sum of all
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    int a[n+1];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<merge_sort(a,0,n-1);
    return 0;
}
