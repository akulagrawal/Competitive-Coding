#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 10006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

// Note:All heaps are binary heaps

void swap2(ll &a,ll &b)                                 //function to swap to long long integers
{
    ll c=a;
    a=b;
    b=c;
}

void heapin(ll a,ll b,ll heapt[],ll heapl[],int &n)     // insert values a and b in min heap of l[] values and keep t[] values with it's corresponding l[] value
{
    heapt[n+1]=a;
    heapl[n+1]=b;
    n++;
    int m=n;
    int j=n/2;
    while(j>0)
    {
        if(b<heapl[j])
        {
            swap2(heapl[n],heapl[j]);
            swap2(heapt[n],heapt[j]);
            n/=2;
            j=n/2;
        }
        else
            break;
    }
    n=m;
}

int minf(ll a[],int l,int i,int r,int n)	// function that returns the index of smallest of ith,lth and rth element of array a[]
{
	if(l>n&&r>n)
		return i;
	else if(l>n)
	{
		if(a[i]<=a[r])
			return i;
		else
			return r;
	}
	else if(r>n)
	{
		if(a[i]<=a[l])
			return i;
		else
			return l;
	}
	else if(a[i]<=a[l]&&a[i]<=a[r])
		return i;
	else if(a[l]<=a[i]&&a[l]<=a[r])
		return l;
	else if(a[r]<=a[l]&&a[r]<=a[i])
		return r;
}

void minheapify(ll heapt[],ll heapl[],int i,int n)      // function to adjust element at i index to its correct position in a heap
{
	int l,r,minm;
	while(1)
	{
		int l=2*i;
		int r=2*i+1;
		minm=minf(heapl,l,i,r,n);
		if(minm==i)
			break;
		else
        {
            swap2(heapt[i],heapt[minm]);
            swap2(heapl[i],heapl[minm]);
        }
		i=minm;
	}
}

void heapout(ll heapt[],ll heapl[],int &n,ll &maxm,ll &ans)     // extract min function to remove the minimum element from the heap
{
    ans+=maxm+heapl[1]-heapt[1];
    maxm+=heapl[1];
    heapt[1]=heapt[n];
    heapl[1]=heapl[n];
    n--;
    minheapify(heapt,heapl,1,n);
}

void merge2(ll a[],ll b[],int l,int mid,int r)		// function to merge 2 arrays in merge sort
{
	int i=l,j=mid+1,k=0;
	ll c[r-l+1],d[r-l+1];
	while((i<=mid)&&(j<=r))
	{
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			d[k]=b[i];
			i++;
		}
		else
		{
			c[k]=a[j];
			d[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		c[k]=a[i];
		d[k]=b[i];
		i++; k++;
	}
	while(j<=r)
	{
		c[k]=a[j];
		d[k]=b[j];
		j++; k++;
	}
	for(i=0;i<k;i++)
    {
        a[l+i]=c[i];
        b[l+i]=d[i];
    }
}

void merge_sort(ll a[],ll b[],int l,int r)      // sort a and b according to increasing order of a by merge sort
{
	if(l==r)
		return;
    int mid=l+(r-l)/2;
    merge_sort(a,b,l,mid);
    merge_sort(a,b,mid+1,r);
    merge2(a,b,l,mid,r);
}

int main()
{
    int n,i,m=0;
    cout<<"Enter total no. of customers : ";
    cin>>n;
    cout<<"Enter ordering time and cooking time of order respectively for "<<n<<" customers\n";
    ll t[n+5],l[n+5],heapt[n+5],heapl[n+5],sum=0,maxm,tout;     // heapl[] is a minheap of elements of l[] and heapt[] consists of corresponding t[] values
    for(i=0;i<n;i++)
        cin>>t[i]>>l[i];
    merge_sort(t,l,0,n-1);
    for(i=0;i<n;i++)
    {
        sum+=l[i];
        maxm=l[i]+t[i];                                 // This element is inserted independent of any other element
        i++;
        for(;i<n;i++)
        {
            if(t[i]<maxm)
                heapin(t[i],l[i],heapt,heapl,m);        // Insert data of all people who come before independent person has finished
            else
                break;
        }
        while(m>0)
        {
            heapout(heapt,heapl,m,maxm,sum);            // choose them in increasing order of time required
            for(;i<n;i++)
            {
                if(t[i]<maxm)
                    heapin(t[i],l[i],heapt,heapl,m);    // add people who are come before person eating at present has finished
            }
        }
    }
    cout<<"minimum avg. waiting time is : "<<sum/n;
    return 0;
}
