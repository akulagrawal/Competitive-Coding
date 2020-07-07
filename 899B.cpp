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

int a[100];
int b[24]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int c[24]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int d[24]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k=0,l;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<24;i++)
    {
        l=i%24;
        for(j=i;j<i+n;j++)
        {
            if(b[j%24]!=a[(j-l)%24])
                break;
        }
        if(j==i+n)
            k=1;
    }
    for(i=0;i<24;i++)
    {
        l=i%24;
        for(j=i;j<i+n;j++)
        {
            if(c[j%24]!=a[(j-l)%24])
                break;
        }
        if(j==i+n)
            k=1;
    }
    for(i=0;i<24;i++)
    {
        l=i%24;
        for(j=i;j<i+n;j++)
        {
            if(d[j%24]!=a[(j-l)%24])
                break;
        }
        if(j==i+n)
            k=1;
    }
    if(k)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
