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

int a[5][10],b[10];
map<int,int> my,my2;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
            cin>>a[i][j];
    }
    for(i=0;i<n;i++)
    {
        memset(b,0,sizeof(b));
        for(j=0;j<6;j++)
        {
            if(!b[a[i][j]])
            {
                my[a[i][j]]++;
                b[a[i][j]]=1;
            }
        }
    }
    for(i=1;i<10;i++)
    {
        if(my[i]==0)
        {
            cout<<i-1;
            return 0;
        }
    }
    if(!my[0])
    {
        cout<<"9";
        return 0;
    }
    int k=1;
    while(k<10)
    {
        int p=0,q=0;
        for(i=0;i<n;i++)
        {
            memset(b,0,sizeof(b));
            for(j=0;j<6;j++)
            {
                if(a[i][j]==k&&!b[a[i][j]])
                {
                    p+=i+2;
                    b[a[i][j]]++;
                }
                if(!a[i][j]&&!b[a[i][j]])
                {
                    q+=i+2;
                    b[a[i][j]]++;
                }
            }
        }
        if(q>4||p>4||p!=q)
            my2[k]++;
        k++;
    }
    for(i=1;i<10;i++)
    {
        if(my[i]==1)
        {
            if(!my2[i])
            {
                if(i==1)
                    cout<<"9";
                else
                    cout<<i-1<<"9";
            }
            else
                cout<<i<<i-1;
            return 0;
        }
    }
    cout<<99;
    return 0;
}
