#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

char s[55][15];
char a[55][15];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,j,p,t=0;
    cin>>n>>k;
    for(i=1;i<=n-k+1;i++)
        cin>>s[i];
    p=0;
    if(s[1][0]=='Y')
        p=1;
    if(p)
    {
        for(j=0;j<2;j++)
        {
            a[j][0]=(char)('A'+t);
            t++;
        }
    }
    else
    {
        for(j=0;j<2;j++)
            a[j][0]='A';
        t=1;
    }
    for(;j<k;j++)
    {
        if(t<26)
            a[j][0]=(char)('A'+t);
        else
        {
            a[j][0]='A';
            a[j][1]=(char)('a'+t-26);
        }
        t++;
    }
    for(i=2;i<=n-k+1;i++)
    {
        if(s[i][0]=='Y')
        {
            if(t<26)
                a[j][0]=(char)('A'+t);
            else
            {
                a[j][0]='A';
                a[j][1]=(char)('a'+t-26);
            }
            t++;
            j++;
        }
        else
        {
            strcpy(a[j],a[j-k+1]);
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        cout<<a[i][0];
        if(a[i][1]>='a'&&a[i][1]<='z')
            cout<<a[i][1];
        cout<<" ";
    }
    return 0;
}
