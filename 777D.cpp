#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 500005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

string s[MAX];
int a[MAX];

int main()
{
    int n,i,m,j,p;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    a[n-1]=s[n-1].size();
    for(i=n-2;i>=0;i--)
    {
        p=0;
        m=min(int(s[i].size()),a[i+1]);
        for(j=1;j<m;j++)
        {
            if(s[i][j]>s[i+1][j])
                break;
            if(s[i][j]<s[i+1][j])
            {
                p=1;
                break;
            }
        }
        if(p)
            a[i]=s[i].size();
        else
        {
            if(j<m)
                a[i]=j;
            else
            {
                if((s[i][m-1]==s[i+1][m-1])&&s[i].size()>m)
                    a[i]=m;
                else
                    a[i]=s[i].size();
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i];j++)
            cout<<s[i][j];
        cout<<"\n";
    }
    return 0;
}
