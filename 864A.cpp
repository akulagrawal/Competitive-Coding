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

int a[200],b[200];
map<int,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,cnt=0,j=0,p=0,q=0,m;
    cin>>n;
    m=n/2;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(!my[a[i]])
        {
            cnt++;
            b[j]=a[i];
            j++;
            my[a[i]]++;
        }
        if(a[i]==b[0])
            p++;
        else if(a[i]==b[1])
            q++;
    }
    if(cnt!=2||p!=m||q!=m||n%2)
        cout<<"NO";
    else
    {
        cout<<"YES\n";
        cout<<b[0]<<" "<<b[1];
    }
    return 0;
}
