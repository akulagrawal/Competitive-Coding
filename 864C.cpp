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
    ll a,b,f,k,c,i,d,e,g,ans=0;
    cin>>a>>b>>f>>k;
    c=max(f,a-f);
    if(k==1)
    {
        if(b<c)
            cout<<"-1";
        else if(b<a)
            cout<<"1";
        else
            cout<<"0";
        return 0;
    }
    c=max(f,2*(a-f));
    if(k==2)
    {
        if(b<c)
            cout<<"-1";
        else if(b<2*a&&b>=(2*a-f))
            cout<<"1";
        else if(b<2*a)
            cout<<"2";
        else
            cout<<"0";
        return 0;
    }
    c=2*max(f,a-f);
    if(b<c)
    {
        cout<<"-1";
        return 0;
    }
    e=b;
    while(k>0)
    {
        d=e/a;
        g=e%a;
        k-=d;
        if(k<=0)
            break;
        ans++;
        if(d%2)
        {
            k--;
            if(a-f<=g)
                e=b-f;
            else
            {
                e=b-a+f;
                if(e>=a)
                    e-=a;
                else
                {
                    e=b-f;
                    ans++;
                }
            }
        }
        else
        {
            if(f<=g)
            {
                e=b-a+f;
                k--;
                if(k<=0)
                    break;
                k--;
                if(e>=a)
                    e-=a;
                else
                {
                    e=b-f;
                    ans++;
                }
            }
            else
                e=b-f;
        }
    }
    cout<<ans;
    return 0;
}
