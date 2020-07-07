#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 200005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int a[MAX],b[MAX];
pair<int,int> c[MAX];

int main()
{
    int n,k,i,sum=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        c[i].f=a[i]-b[i];
        c[i].s=i;
    }
    sort(c,c+n);
    for(i=0;i<k;i++)
        sum+=a[c[i].s];
    while(c[i].f<0&&i<n)
    {
        sum+=a[c[i].s];
        i++;
    }
    while(i<n)
    {
        sum+=b[c[i].s];
        i++;
    }
    printf("%d",sum);
    return 0;
}
