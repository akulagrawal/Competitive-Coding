#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 500005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int t[MAX],s[INF];

int main()
{
    int n,k,i,minm=INF;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&t[i]);
    for(i=0;i<n;i++)
    {
        if(k<=t[i]||k==(2*t[i]))
            continue;
        if(!s[t[i]])
            s[t[i]]=min(i+1,n-i);
        else
            s[t[i]]=min(s[t[i]],min(i+1,n-i));
        if(s[k-t[i]])
            minm=min(minm,max(s[k-t[i]],s[t[i]]));
    }
    if(minm==INF)
        minm=-1;
    printf("%d",minm);
    return 0;
}
