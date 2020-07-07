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

int power(int x,int n)
{
    int val=x,prod=1;
    while(n)
    {
        if(n%2)
            prod*=val;
        val*=val;
        n/=2;
    }
    return prod;
}

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k,i,sum,m,o;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(!k)
        {
            cout<<-1<<endl;
            continue;
        }
        sum=0;
        m=0;
        for(i=0;;i++)
        {
            if(!n)
                break;
            a[i]=n%2;
            if(a[i])
                sum++;
            n/=2;
        }
        o=sum;
        n=i;
        for(i=0;i<(n-2);i++)
        {
            if(a[n-i-1]&&(sum==1||(o-sum)==k-1))
                break;
            m+=a[n-i-1]*power(2,n-i-1);
            if(a[n-i-1])
                sum--;
        }
        if((o-sum)==k-1)
        {
            cout<<m+1<<endl;
            continue;
        }
        i++;
        for(;i<n-1;i++)
        {
            if((o-sum)==k-1)
                break;
            m+=power(2,n-i-1);
            sum--;
        }
        cout<<m+1<<endl;
    }
    return 0;
}
