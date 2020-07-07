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

long l1[MAX],l2[MAX],r1[MAX],r2[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int n,i,m;
    long l,r,maxl1,maxl2,minr1,minr2,maxm;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>l1[i]>>r1[i];
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>l2[i]>>r2[i];
    }
    maxl1=l1[0];
    minr1=r1[0];
    maxl2=l2[0];
    minr2=r2[0];
    for(i=0;i<n;i++)
    {
        maxl1=max(maxl1,l1[i]);
        minr1=min(minr1,r1[i]);
    }
    for(i=0;i<m;i++)
    {
        maxl2=max(maxl2,l2[i]);
        minr2=min(minr2,r2[i]);
    }
    maxm=max(maxl2-minr1,maxl1-minr2);
    cout<<max((long)0,maxm);
    return 0;
}
