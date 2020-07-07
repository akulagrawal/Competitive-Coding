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

int a[MAX],b[MAX];
map<int,int> my,my1;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        my[a[i]]++;
    }
    j=0;
    for(i=1;i<=n;i++)
    {
        if(!my[i])
        {
            while(j<n)
            {
                if(my[a[j]]>1&&((a[j]>i)||my1[a[j]]>0))
                {
                    my[a[j]]--;
                    b[j]=i;
                    ans++;
                    j++;
                    break;
                }
                else if(my[a[j]]>1)
                    my1[a[j]]++;
                j++;
            }
        }
    }
    cout<<ans<<endl;
    for(i=0;i<n;i++)
    {
        if(b[i])
            cout<<b[i]<<" ";
        else
            cout<<a[i]<<" ";
    }
    return 0;
}
