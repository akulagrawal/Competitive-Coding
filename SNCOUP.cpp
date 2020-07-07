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

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,p,ans,p1,p2,ans1;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        p=0;
        p1=0;
        p2=0;
        ans=0;
        cin>>s1>>s2;
        for(i=0;i<n;i++)
        {
            if(s1[i]=='*'&&s2[i]=='*')
            {
                p=1;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(s1[i]=='*')
                p1++;
            if(s2[i]=='*')
                p2++;
        }
        ans1=p1+p2-1;
        if(ans1<0)
            ans1=0;
        p1=p;
        {
            p=-1;
            for(i=0;i<n;i++)
            {
                if(s1[i]=='*'&&s2[i]=='*')
                {
                    if(p!=-1)
                        ans++;
                    ans++;
                    p=-1;
                }
                else if(s1[i]=='*')
                {
                    if(p==1)
                    {
                        ans++;
                        p=-1;
                    }
                    else if(!p)
                        ans++;
                    else
                        p=0;
                }
                else if(s2[i]=='*')
                {
                    if(!p)
                    {
                        ans++;
                        p=-1;
                    }
                    else if(p==1)
                        ans++;
                    else
                        p=1;
                }
            }
            if(p!=-1)
                ans+=1;
        }
        if(p1)
            cout<<ans<<endl;
        else
            cout<<min(ans,ans1)<<endl;
    }
    return 0;
}
