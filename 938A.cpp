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
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(i>0&&(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u'||s[i-1]=='y')&&(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'))
            continue;
        cout<<s[i];
    }
    return 0;
}
