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

int a[MAX],b[MAX],c[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    string s;
    cin>>s;
    sort(b,b+n);
    int j=0;
    int p=1;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            c[j]=a[i];
            j++;
            sort(c,c+j);
            for(int k=0;k<j;k++)
            {
                if(c[k]!=b[i-j+k+1])
                {
                    p=0;
                    break;
                }
            }
            j=0;
        }
        else
        {
            c[j]=a[i];
            j++;
        }
    }
    if(p)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
