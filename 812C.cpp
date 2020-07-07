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

long a[MAX];
ll b[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,start,mid,end1,ans1=0;
    ll s,sum=0,ans2=0;
    cin>>n>>s;
    for(i=0;i<n;i++)
        cin>>a[i];
    start=1;
    end1=n;
    mid=start+(end1-start)/2;
    while(start<end1)
    {
        mid=start+(end1-start)/2;
        sum=0;
        for(i=0;i<n;i++)
            b[i]=(ll)a[i]+(ll)mid*(ll)(i+1);
        sort(b,b+n);
        for(i=0;i<mid;i++)
        {
            sum+=b[i];
            if(sum>s)
                break;
        }
        if(sum>s)
            end1=mid;
        else
        {
            ans1=mid;
            ans2=sum;
            start=mid+1;
        }
    }
    mid=start+(end1-start)/2;
    sum=0;
    for(i=0;i<n;i++)
        b[i]=(ll)a[i]+(ll)mid*(ll)(i+1);
    sort(b,b+n);
    for(i=0;i<mid;i++)
    {
        sum+=b[i];
        if(sum>s)
            break;
    }
    if(sum<=s)
    {
        ans1=mid;
        ans2=sum;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
