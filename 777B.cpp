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

string s,m;
int a[1003],b[1003];

int main()
{
    int n,i,j=-1,ans1=0,ans2=0;
    cin>>n;
    cin>>s>>m;
    for(i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
        b[i]=m[i]-'0';
    }
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
        for(;j<n-1;)
        {
            j++;
            if(b[j]>a[i])
            {
                ans2++;
                break;
            }
        }
    }
    j=n;
    for(i=n-1;i>=0;i--)
    {
        for(;j>0;)
        {
            j--;
            if(a[j]<=b[i])
            {
                ans1++;
                break;
            }
        }
    }
    ans1=n-ans1;
    cout<<ans1<<"\n"<<ans2;
    return 0;
}
