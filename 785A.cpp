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

string s[200005];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    int n,a=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i][0]=='T')
            a+=4;
        else if(s[i][0]=='C')
            a+=6;
        else if(s[i][0]=='O')
            a+=8;
        else if(s[i][0]=='D')
            a+=12;
        else if(s[i][0]=='I')
            a+=20;
    }
    cout<<a;
    return 0;
}
