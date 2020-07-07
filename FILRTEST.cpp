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

int lps[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,len,k,ans;
    string s;
    while(1)
    {
        cin>>n>>s;
        if(n==-1&&s[0]=='*')
            break;
        m=s.size();
        if(n<m)
        {
            cout<<"0\n";
            continue;
        }
        len=0;
        for(i=1;i<m;i++)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
            }
            else
            {
                if(len)
                {
                    len=lps[len-1];
                    i--;
                }
                else
                    lps[i]=0;
            }
        }
        ans=(n-lps[m-1])/(m-lps[m-1]);
        cout<<ans<<"\n";
    }
    return 0;
}
