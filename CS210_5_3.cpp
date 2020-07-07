#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

void swap2(int &a,int &b)                                               //function to swap two integers
{
    int temp=a;
    a=b;
    b=temp;
}

int part(int h[],int p[],int idx[],int l,int r)                         // partition function for quick sort, returns the index of pivot
{                                                                       // all the elements with either equal h and greater p or lesser h are put in left of pivot
    int rc=r,lc=l;
    int pivot1=h[l],pivot2=p[l];
    while(lc<=rc)
    {
        while(lc<=rc&&((h[lc]<pivot1)||((h[lc]==pivot1)&&(p[lc]>=pivot2))))
            lc++;
        while(lc<=rc&&((h[rc]>pivot1)||((h[rc]==pivot1)&&(p[rc]<pivot2))))
            rc--;
        if(lc<=rc)
        {
            swap2(h[lc],h[rc]);
            swap2(p[lc],p[rc]);
            swap2(idx[lc],idx[rc]);
        }
    }
    swap2(h[l],h[rc]);
    swap2(p[l],p[rc]);
    swap2(idx[l],idx[rc]);
    return rc;
}

void qsort1(int h[],int p[],int idx[],int l,int r)          // function to sort arrays so as to arrange elements in increasing order of h for distinct h
{                                                           // and decreasing order of p for same h
    if(l<r)                                                 // idx index of element in original array
    {
        int i=part(h,p,idx,l,r);
        qsort1(h,p,idx,l,i-1);
        qsort1(h,p,idx,i+1,r);
    }
}

int main()
{
    int n,t,e,i,m=0;
    cout<<"Enter no. of towns and the town where office is located followed by no. of employees\n";
    cin>>n>>t>>e;
    cout<<"Enter description of each employee which includes his home town and no. of people he can drive\n";
    int h[e+1],p[e+1],idx[e+1],cnt[MAX],ans[e+1];           // idx array stores the original index of elements
    for(i=0;i<e;i++)                                        // cnt array stores number of employees in a given town
        ans[i]=0;
    for(i=0;i<MAX;i++)
        cnt[i]=0;
    for(i=0;i<e;i++)
    {
        cin>>h[i]>>p[i];
        if(!cnt[h[i]])
            m++;                                            // m is the no. of distinct towns in which employees live (in input)
        cnt[h[i]]++;
        idx[i]=i;
    }
    qsort1(h,p,idx,0,e-1);
    for(i=0;i<e;i++)
    {
        if(cnt[h[i]]<=0)
            continue;
        cnt[h[i]]-=p[i];
        ans[idx[i]]=1;
        if(cnt[h[i]]<=0)
            m--;
    }
    if(m>0)
        cout<<"IMPOSSIBLE\n";
    else
    {
        for(i=0;i<e;i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}
