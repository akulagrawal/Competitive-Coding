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

ll a[MAX];
ll b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,i,j,m;
    char ch='a';
    cin>>k;
    if(!k)
    {
        cout<<"a";
        return 0;
    }
    if(k==1)
    {
        cout<<"aa";
        return 0;
    }
    for(i=0;i<k;i++)
        b[i]=i+1;
    for(i=1;i<k;i++)
    {
        a[i]=b[i-1]+a[i-1];
        if(a[i]>k)
            break;
    }
    m=min(i+1,k);
    i=m-1;
    while(k)
    {
        for(;i>0;i--)
            if(a[i]<=k)
                break;
        for(j=0;j<b[i];j++)
            cout<<ch;
        k-=a[i];
        ch++;
    }
    return 0;
}
