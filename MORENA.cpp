#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 1000005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

ll a[MAX];
int b[MAX],c[MAX];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    b[0]=1;
    c[0]=1;
    if(n>1)
    {
        b[1]=1;
        c[1]=1;
        if(a[1]>a[0])
            b[1]++;
        else if(a[1]<a[0])
            c[1]++;
    }
    for(i=2;i<n;i++)
    {
        b[i]=b[i-1];
        c[i]=c[i-1];
        if(a[i]>a[i-1])
            b[i]=max(b[i-1],c[i-1]+1);
        else if(a[i]<a[i-1])
            c[i]=max(c[i-1],b[i-1]+1);
    }
    printf("%d",max(b[n-1],c[n-1]));
    return 0;
}
