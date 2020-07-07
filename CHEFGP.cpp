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
    int t,x,y,n,na,nb,i,j,k;
    string s,s2;
    stack<int> a,b;
    cin>>t;
    while(t--)
    {
        na=0;
        nb=0;
        k=0;
        cin>>s;
        s2=s+s;
        cin>>x>>y;
        n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]=='a')
                na++;
            else
                nb++;
        }
        if(na)
            a.push(0);
        else
            b.push(0);
        while(na&&nb)
        {
            if(na)
            {
                s2[k]='a';
                k++;
                na--;
            }
            for(j=0;j<x-1;j++)
            {
                if(!na)
                    break;
                s2[k]='a';
                k++;
                na--;
                a.push(k-1);
            }
            if(nb)
            {
                s2[k]='b';
                k++;
                nb--;
            }
            for(j=0;j<y-1;j++)
            {
                if(!nb)
                    break;
                s2[k]='b';
                k++;
                nb--;
                b.push(k-1);
            }
        }
        while(na)
        {
            if(k>=1&&s2[k-1]=='a')
            {
                if(!b.empty())
                {
                    j=b.top();
                    b.pop();
                    s2[j]='#';
                    s2[k]='b';
                }
                else
                    s2[k]='*';
                k++;
            }
            for(j=0;j<x;j++)
            {
                if(!na)
                    break;
                s2[k]='a';
                k++;
                na--;
            }
        }
        while(nb)
        {
            if(k>=1&&s2[k-1]=='b')
            {
                if(!a.empty())
                {
                    j=a.top();
                    a.pop();
                    s2[j]='#';
                    s2[k]='a';
                }
                else
                    s2[k]='*';
                k++;
            }
            for(j=0;j<y;j++)
            {
                if(!nb)
                    break;
                s2[k]='b';
                k++;
                nb--;
            }
        }
        for(i=0;i<k;i++)
        {
            if(s2[i]!='#')
                cout<<s2[i];
        }
        cout<<endl;
        while(!a.empty())
            a.pop();
        while(!b.empty())
            b.pop();
    }
    return 0;
}
