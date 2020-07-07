#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

void swap2(int &a,int &b)           // function to swap 2 integers
{
	int temp=a;
	a=b;
	b=temp;
}

int mini(int H[],int n,int a,int b,int c,int d)                     // function hat returns index of minimum of ath, bth, cth and dth element of array H[]
{                                                                   // used to find position of minimum of parent and its 3 children
	if(((b>=n)||(H[a]<=H[b]))&&((c>=n)||(H[a]<=H[c]))&&((d>=n)||H[a]<=H[d]))
		return a;
	if(((c>=n)||H[b]<=H[c])&&((d>=n)||H[b]<=H[d]))
		return b;
	if((d>=n)||H[c]<=H[d])
		return c;
	return d;
}

void minheapify(int H[],int n,int i)            // function to move ith element to its place in heap
{                                               // swap parent with child till it is the minimum among itself and children
	int l=3*i+1;
	int m=3*i+2;
	int r=3*i+3;
	int k=mini(H,n,i,l,m,r);
	if(k!=i)
	{
		swap2(H[i],H[k]);
		minheapify(H,n,k);
	}
}

void buildheap(int H[],int n)           // build the min heap from array H[]
{
	int m=(2*n+1)/3;
	m=n-m-1;
	for(int i=m;i>=0;i--)
		minheapify(H,n,i);
}

int deletemin(int H[],int &n)       // delete the minimum element of heap H[], reduce size by 1 and return minimum element
{
	int a=H[0];
	swap2(H[0],H[n-1]);
	n--;
	minheapify(H,n,0);
	return a;
}

void show(int H[],int n)            // print elements of heap of size n
{
	int i;
	cout<<"Current Heap :\n";
	for(i=0;i<n;i++)
		cout<<H[i]<<" ";
	cout<<endl<<endl;
}

void ksmallest(int H[],int n,int k)             // print k smallest elements of heap H[] while keeping H[] same
{
    int temp[n+1],i,m=n;
    if(n<k)
    {
        cout<<"Error! Heap Size less than k\nListing all elements :\n";     // Error if trying to print elements more than size of heap
        k=n;
    }
    for(i=0;i<n;i++)
        temp[i]=H[i];
    for(i=0;i<k;i++)                    // use a temp array to change and take k smallest elements
        cout<<deletemin(temp,m)<<" ";
    cout<<endl<<endl;
}

void printsmall(int H[],int n,int a)            // print all elements of heap smaller than a
{
    int temp[n+1],i,m=n;        // copying H to temp to keep H unchanged
    for(i=0;i<n;i++)
        temp[i]=H[i];
    for(i=0;i<n;i++)
    {
        if(temp[0]>a)           // if smallest element of heap is greater than a, then stop printing
            break;
        cout<<deletemin(temp,m)<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
	int n,x,i,k,a;
	char ch;
	cout<<"Enter size of heap : ";
	cin>>n;
	int H[n+1];
	cout<<"Enter n elements of heap : ";
	for(i=0;i<n;i++)
		cin>>H[i];
	buildheap(H,n);
	show(H,n);
	cout<<"Enter k to print k smallest integers : ";
	cin>>k;
	ksmallest(H,n,k);
	show(H,n);
	cout<<"Enter a to print all integers less than or equal to a : ";
	cin>>a;
	printsmall(H,n,a);
	show(H,n);
	return 0;
}
