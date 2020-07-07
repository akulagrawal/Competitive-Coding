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

int sal[1003],ofr[1003],job[1003];
string q[1003];
map<int,int> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,i,j,k,x,p,z;
    ll sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        p=0;
        z=0;
        my.clear();
        cin>>n>>m;
        for(i=0;i<n;i++)
            cin>>sal[i];
        for(i=0;i<m;i++)
            cin>>ofr[i]>>job[i];
        for(i=0;i<n;i++)
            cin>>q[i];
        for(i=0;i<n;i++)
        {
            k=sal[i];
            x=-1;
            for(j=0;j<m;j++)
            {
                if(q[i][j]=='1'&&job[j]>0&&ofr[j]>k)
                {
                    k=ofr[j];
                    x=j;
                }
            }
            if(x>=0)
            {
                sum+=(ll)ofr[x];
                job[x]--;
                if(!my[x])
                {
                    z++;
                    my[x]=1;
                }
            }
            else
                p++;
        }
        cout<<n-p<<" "<<sum<<" "<<m-z<<endl;
    }
    return 0;
}
