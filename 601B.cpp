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

ll a[MAX];
ll b[MAX],c[MAX];
stack<int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=n;i>1;i--)
        a[i]=abs(a[i]-a[i-1]);
    my.push(2);
    i=3;
    while(i<=n)
    {
        while(i<=n&&(my.size()>0)&&a[i]<=a[my.top()])
        {
            my.push(i);
            i++;
        }
        while(i<=n&&(my.size()>0)&&a[i]>a[my.top()])
        {
            int j=my.top();
            c[j]=i-j-1;
            my.pop();
        }
        if(i<=n)
        {
            if(my.size()>0)
                b[i]=i-my.top()-1;
            else
                b[i]=i-1;
            my.push(i);
            i++;
        }
    }
    while(my.size()>0)
    {
        c[my.top()]=n-my.top();
        my.pop();
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        ll ans=0;
        for(i=l+1;i<=r;i++)
            ans+=(min(b[i]+1,(ll)i-l)*min(c[i]+1,(ll)r-i+1))*a[i];
        cout<<ans<<endl;
    }
    return 0;
}
