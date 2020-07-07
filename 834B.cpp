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

string s;
int a[50],b[50];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,ans=0;
    cin>>n>>k;
    cin>>s;
    for(i=0;i<n;i++)
        a[s[i]-'A']++;
    for(i=0;i<n;i++)
    {
        if(!b[s[i]-'A'])
        {
            ans++;
            b[s[i]-'A']++;
            a[s[i]-'A']--;
        }
        else
            a[s[i]-'A']--;
        if(ans>k)
        {
            cout<<"YES";
            return 0;
        }
        if(!a[s[i]-'A'])
            ans--;
    }
    cout<<"NO";
    return 0;
}
