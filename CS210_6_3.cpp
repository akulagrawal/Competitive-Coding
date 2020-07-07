#include<bits/stdc++.h>
using namespace std;
#define ll long long

void swap2(ll &a,ll &b)                 //function to swap to long long integers
{
    ll c=a;
    a=b;
    b=c;
}

void heapin(ll a,ll heap[],int &n)      // insert value a in min heap and increment size of heap by one
{
    heap[n+1]=a;
    n++;
    int m=n;
    int j=n/2;
    while(j>0)
    {
        if(a<heap[j])
        {
            swap2(heap[n],heap[j]);
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

void minheapify(ll heap[],int i,int n)      // function to adjust element at i index to its correct position in heap[]
{
	int l,r,minm;
	while(1)
	{
		int l=2*i;
		int r=2*i+1;
		minm=minf(heap,l,i,r,n);
		if(minm==i)
			break;
		else
            swap2(heap[i],heap[minm]);
		i=minm;
	}
}

void heapout(ll heap[],int &n)     // extract min function to remove the minimum element from the heap
{
    heap[1]=heap[n];
    n--;
    minheapify(heap,1,n);
}

int countno(string s[],ll a[],int n)    // function that returns minimum no. of statements required for input to be valid
{
    int ans=0,i,m=0;
    ll heap[n+1];
    for(i=0;i<n;i++)
    {
        if(s[i][0]=='i')
        {
            heapin(a[i],heap,m);        // insert the given no. in heap takes 1 statement
            ans++;
        }
        else if(s[i][0]=='r')
        {
            if(m>0)
                heapout(heap,m);        // remove if possible takes 1 statement
            else
                ans++;                  // if can't remove, insert any element first, so additional statement required
            ans++;
        }
        else
        {
            while(m>0&&a[i]>heap[1])
            {
                heapout(heap,m);        // remove min. till it is greater than desired min
                ans++;
            }
            if(m>0&&heap[1]==a[i])     // if min of heap is desired min, statement is valid
                ans++;
            else                        // else insert the desired min. first, thus, 1 additional statement required
                ans+=2;
        }
    }
    return ans;
}

int main()
{
    int n,i,m=0;
    cout<<"Enter no. of statements in input : ";
    cin>>n;
    ll a[n+1],heap[n+1];
    string s[n+1];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i][0]!='r')
            cin>>a[i];
    }
    cout<<countno(s,a,n)<<endl;
    for(i=0;i<n;i++)
    {
        if(s[i][0]=='i')
        {
            heapin(a[i],heap,m);
            cout<<"insert "<<a[i]<<endl;    // insert in heap whenever insert input
        }
        else if(s[i][0]=='r')
        {
            if(m>0)
            {
                heapout(heap,m);            // remove from heap if possible
                cout<<"removeMin\n";
            }
            else
            {
                cout<<"insert 0\n";         // if not possible, insert 0(any number) in heap first
                cout<<"removeMin\n";
            }
        }
        else
        {
            while(m>0&&a[i]>heap[1])
            {
                heapout(heap,m);
                cout<<"removeMin\n";        // while min in heap is greater than a[i], remove it
            }
            if(m>0&&heap[1]==a[i])
                cout<<"getMin "<<a[i]<<endl;    // if min in heap is equal to a[i], then we are done
            else
            {
                cout<<"insert "<<a[i]<<endl;    // otherwise insert a[i] first
                cout<<"getMin "<<a[i]<<endl;
            }
        }
    }
    return 0;
}
