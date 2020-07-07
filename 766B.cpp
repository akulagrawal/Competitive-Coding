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

long a[100005];

int main()
{
    int n,i,p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    sort(a,a+n);
    for(i=0;i<n-2;i++)
    {
        if(a[i+2]<(a[i]+a[i+1]))
            p++;
    }
    if(p>0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
