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

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,sum=0,i;
    string s;
    cin>>k>>s;
    n=s.size();
    for(i=0;i<n;i++)
        a[i]=s[i]-'0';
    sort(a,a+n);
    for(i=0;i<n;i++)
        sum+=a[i];
    i=0;
    while(i<n&&sum<k)
    {
        sum+=9-a[i];
        i++;
    }
    cout<<i;
    return 0;
}
