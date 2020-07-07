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

int x1[100],t1[100],x2[100],t2[100],maxm[100][100];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,x,y,j,k,s1,s2,p,ans;
    cin>>t;
    while(t--)
    {
        x=0;
        y=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x1[i]>>t1[i]>>x2[i]>>t2[i];
            x=max(x,max(x1[i],x2[i]));
            y=max(y,max(t1[i],t2[i]));
        }
        for(i=1;i<=x;i++)
        {
            for(j=1;j<=y;j++)
            {
                p=0;
                for(k=0;k<n;k++)
                {
                    s1=(i-x1[k])*(i-x2[k]);
                    s2=(j-t1[k])*(j-t2[k]);
                    if(s1>0||s2>0)
                    {
                        if(t1[k]==t2[k])
                        {
                            ans=abs(j-t1[k]);
                            if(s1<=0)
                                p=max(p,ans);
                            else
                                p=max(p,ans+min(abs(i-x1[k]),abs(i-x2[k])));
                        }
                        else
                        {
                            ans=abs(i-x1[k]);
                            if(s2<=0)
                                p=max(p,ans);
                            else
                                p=max(p,ans+min(abs(j-t1[k]),abs(j-t2[k])));
                        }
                    }
                }
                maxm[i][j]=p;
            }
        }
        ans=maxm[1][1];
        for(i=1;i<=x;i++)
        {
            for(j=1;j<=y;j++)
            {
                ans=min(ans,maxm[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
