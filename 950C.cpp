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

int a[MAX],b[MAX], c[MAX];
vector<int> v[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    int i,j=0;
    for(i=0;i<=n;i++)
        a[i]=b[i]=MAX;
    while((j<n)&&(s[j]!='0'))
        j++;
    for(i=0;i<n;i++)
    {
        if((s[i]=='1')&&(j<i)&&(s[j]=='0'))
        {
            a[j]=i;
            j++;
        }
        while(j<i&&s[j]!='0')
            j++;
    }
    j=0;
    while((j<n)&&(s[j]!='1'))
        j++;
    for(i=0;i<n;i++)
    {
        if((s[i]=='0')&&(j<i)&&(s[j]=='1'))
        {
            b[j]=i;
            j++;
        }
        while(j<i&&s[j]!='1')
            j++;
    }
    int k=0;
    for(i=0;i<n;i++)
    {
        if((!c[i])&&(s[i]=='0'))
        {
            k++;
            v[k].pb(i);
            j=i;
            c[i]=1;
            while((a[j]<n) && (b[a[j]]<n))
            {
                v[k].pb(a[j]);
                v[k].pb(b[a[j]]);
                c[a[j]]=1;
                c[b[a[j]]]=1;
                j=b[a[j]];
            }
        }
        else if((!c[i])&&(s[i]=='1'))
            break;
    }
    if((!k)||(i<n))
        cout<<-1;
    else
    {
        cout<<k<<endl;
        for(i=1;i<=k;i++)
        {
            cout<<v[i].size()<<" ";
            for(j=0;j<v[i].size();j++)
                cout<<v[i][j]+1<<" ";
            cout<<endl;
        }
    }
    return 0;
}
