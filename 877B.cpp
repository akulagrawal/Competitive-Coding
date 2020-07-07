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

int a[5005],b[5005],c[5005],d[5005],e[5005];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n,i;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            a[i+1]=a[i]+1;
            b[i+1]=max(b[i],c[i])+1;
            c[i+1]=c[i];
            d[i+1]=d[i];
            e[i+1]=max(e[i],d[i])+1;
        }
        else
        {
            a[i+1]=a[i];
            b[i+1]=b[i];
            c[i+1]=c[i]+1;
            d[i+1]=max(a[i],d[i])+1;
            e[i+1]=e[i];
        }
    }
    int maxm=max(a[n],b[n]),maxm2=max(c[n],d[n]);
    maxm=max(maxm,maxm2);
    maxm=max(maxm,e[n]);
    cout<<maxm;
    return 0;
}
