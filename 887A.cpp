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
    string s;
    cin>>s;
    int i,j=0;
    for(i=0;i<s.size();i++)
        if(s[i]!='0')
            break;
    //i--;
    for(;i<s.size();i++)
        if(s[i]=='0')
            j++;
    if(j>=6)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
