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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i;
    int x=0;
    int y=MAX;
    for(i=0;i<n;i++)
    {
        x=max(x,(int)(char)s[i]);
        y=min(y,(int)((char)s[i]));
    }
    if(k>n)
    {
        for(i=0;i<n;i++)
            cout<<s[i];
        for(i=n;i<k;i++)
            cout<<(char)y;
        return 0;
    }
    int j=0;
    for(j=k-1;j>=0;j--)
    {
        if((int)(char)s[j]<x)
            break;
    }
    for(i=0;i<j;i++)
        cout<<s[i];
    for(i=0;i<n;i++)
        if(s[i]>s[j])
            x=min(x,(int)(char)s[i]);
    cout<<(char)x;
    for(i=j+1;i<k;i++)
        cout<<(char)y;
    return 0;
}
