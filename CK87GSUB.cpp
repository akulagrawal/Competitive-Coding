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
    int t,n,i,j;
    ll ans,k;
    char ch;
    string a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        n=a.size();
        ans=0;
        k=0;
        k++;
        ch='.';
        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                if(a[i]==ch)
                    ans++;
                ans+=k*(k-1)/2;
                k=1;
                ch=a[i-1];
            }
            else
                k++;
        }
        ans+=k*(k-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
