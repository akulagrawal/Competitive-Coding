#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int a[102],b[102],c[10],d[10];

int main()
{
    int n,i,sum=0,p=0,q=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
        c[a[i]]++;
        d[b[i]]++;
    }
    for(i=1;i<6;i++)
    {
        if(c[i]-d[i]>0)
            p+=c[i]-d[i];
        else
            q+=d[i]-c[i];
        if(p%2||q%2)
        {
            printf("-1");
            return 0;
        }
    }
    if(p!=q&&(min(p,q)%4!=0))
        printf("-1");
    else
    {
        if(p==q)
            sum=p/2;
        else
            sum=(max(p,q)/2)+(min(p,q)/4);
        printf("%d",sum);
    }
    return 0;
}
