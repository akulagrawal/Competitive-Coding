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
    int h,i,k;
    cin>>h;
    for(i=0;i<=h;i++)
        cin>>a[i];
    for(i=1;i<=h;i++)
    {
        if(a[i]>1&&a[i-1]>1)
            break;
    }
    if(i>h)
        cout<<"perfect";
    else
    {
        cout<<"ambiguous\n";
        int k=0;
        for(i=0;i<=h;i++)
        {
            for(int j=0;j<a[i];j++)
                cout<<k<<" ";
            k+=a[i];
        }
        cout<<endl;
        k=0;
        int p=0;
        for(i=0;i<=h;i++)
        {
            if(i>0&&a[i]>1&&a[i-1]>1)
            {
                cout<<k<<" "<<k-1<<" ";
                a[i]-=2;
                p+=2;
            }
            for(int j=0;j<a[i];j++)
                cout<<k<<" ";
            k+=a[i]+p;
            p=0;
        }
    }
    return 0;
}
