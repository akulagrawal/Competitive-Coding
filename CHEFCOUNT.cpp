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

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            result = result*value;
        value = value*value;
        power /= 2;
    }
    return result;
}

ll k=pow(2,32),m=99999,l;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,i;
    ll p;
    k-=100000;
    p=k/m;
    p-=2;
    k-=(p*m);
    cin>>t;
    while(t--)
    {
        l=k;
        cin>>n;
        for(i=0;i<p;i++)
        {
            cout<<m<<" ";
            n--;
        }
        cout<<"100000 ";
        n--;
        k-=100000;
        cout<<k-n+1<<" ";
        n--;
        for(int i=0;i<n;i++)
            cout<<"1 ";
        cout<<endl;
        k=l;
    }
    return 0;
}
