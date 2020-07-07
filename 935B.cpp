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
    int n,x=0,y=0;
    string s;
    cin>>n>>s;
    int i,p=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='R')
            x++;
        else
            y++;
        if(x==y)
        {
            if(i<n-1&&s[i]==s[i+1])
                p++;
        }
    }
    cout<<p;
    return 0;
}
