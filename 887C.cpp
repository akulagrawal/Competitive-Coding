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

int func(int a[])
{
    int i,j,k,l,p=0,q=0;
    for(i=1;i<=16;i+=4)
    {
        j=i+2;
        if(i<12)
            k=i+5;
        else
            k=2;
        if(j<12)
            l=j+5;
        else
            l=4;
        if(a[i]!=a[j]||a[i]!=a[k]||a[i]!=a[l])
            p=1;
    }
    for(i=2;i<=16;i+=4)
    {
        j=i+2;
        if(i<14)
            k=i+3;
        else
            k=1;
        if(j<14)
            l=j+3;
        else
            l=3;
        if(a[i]!=a[j]||a[i]!=a[k]||a[i]!=a[l])
            q=1;
    }
    for(i=18;i<21;i++)
        if(a[i]!=a[17])
            p=q=1;
    for(i=22;i<25;i++)
        if(a[i]!=a[21])
            p=q=1;
    if(!p||!q)
        return 1;
    return 0;
}

int a[25];
int b[25]={0,19,17,20,18,7,5,8,6,23,21,24,22,14,16,13,15,11,9,12,10,3,1,4,2};
int c[25]={0,17,18,19,20,11,9,12,10,24,23,22,21,2,4,1,3,15,13,16,14,7,5,8,6};
int d[25],e[25];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,p,q,r;
    for(i=1;i<=12;i++)
        cin>>a[i];
    for(i=17;i<=24;i++)
        cin>>a[i];
    for(i=16;i>12;i--)
        cin>>a[i];
    p=func(a);
    for(i=1;i<=24;i++)
    {
        d[i]=a[b[i]];
        e[i]=a[c[i]];
    }
    q=func(e);
    r=func(d);
    if(p||q||r)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
