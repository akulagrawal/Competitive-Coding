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

int a[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p=0;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int m=0;
    for(i=n-1;i>=0;i--)
    {
        if(i==n-1||a[i]!=a[i+1])
        {
            if(m%2)
            {
                cout<<"Conan";
                return 0;
            }
            m=0;
        }
        m++;
    }
    if(m%2)
        cout<<"Conan";
    else
        cout<<"Agasa";
    return 0;
}
