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

int l[5],s[5],r[5],p[5];
int t[8]={3,4,1,2,3,4,1,2};

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,ans=0;
    for(i=1;i<=4;i++)
        cin>>l[i]>>s[i]>>r[i]>>p[i];
    for(i=1;i<=4;i++)
    {
        if((l[i]&&p[t[i]])||(l[i]&&p[i]))
        {
            ans=1;
            break;
        }
        if((s[i]&&p[t[i-1]])||(s[i]&&p[i]))
        {
            ans=1;
            break;
        }
        if((r[i]&&p[t[i+2]])||(r[i]&&p[i]))
        {
            ans=1;
            break;
        }
    }
    if(ans)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
