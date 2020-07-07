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

char s[105][105];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,m,minc=MAX,minr=MAX,maxc=-1,maxr=-1,c1,c2,p=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='B')
            {
                minc=min(minc,j);
                minr=min(minr,i);
                maxc=max(maxc,j);
                maxr=max(maxr,i);
                p++;
            }
        }
    }
    if(minc==MAX)
    {
        cout<<"1";
        return 0;
    }
    c1=maxc-minc+1;
    c2=maxr-minr+1;
    if(max(c1,c2)>min(m,n))
    {
        cout<<"-1";
        return 0;
    }
    c1=max(c1,c2);
    cout<<(c1*c1)-p;
    return 0;
}
