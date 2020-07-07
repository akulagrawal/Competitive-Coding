#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
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
    int t,n,i,ans,k,m;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ans=0;
        k=0;
        n=s.size();
        for(i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans++;
                i++;
            }
        }
        for(i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                k++;
                i++;
            }
        }
        k=max(k,ans);
        ans=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='s')
                ans++;
        }
        m=n-ans;
        ans-=k;
        if(ans>m)
            cout<<"snakes\n";
        else if(ans<m)
            cout<<"mongooses\n";
        else
            cout<<"tie\n";
    }
    return 0;
}
