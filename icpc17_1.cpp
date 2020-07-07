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

pii a[5],b[5],c[5];

bool sortbysec(int x,
              int y)
{
    if(a[x].f!=a[y].f)
        return a[x].f<a[y].f;
    if(b[x].f!=b[y].f)
        return b[x].f<b[y].f;
    if(c[x].f!=c[y].f)
        return c[x].f<c[y].f;
    return (x < y);	// put any function according to which arrange array
}

map<int,int> my1,my2,my3;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,i;
    cin>>t;
    while(t--)
    {
        int r[3]={0,1,2};
        for(i=0;i<3;i++)
        {
            cin>>a[i].f>>b[i].f>>c[i].f;
            a[i].s=b[i].s=c[i].s=i;
        }
        sort(r,r+3,sortbysec);
        int j;
        for(j=0;j<2;j++)
        {
            i=r[j];
            if((a[i].s!=b[i].s)||(a[i].s!=c[i].s))
            {
                cout<<"no\n";
                break;
            }
            if(a[i].f==a[r[j+1]].f&&b[i].f==b[r[j+1]].f&&c[i].f==c[r[j+1]].f)
            {
                cout<<"no\n";
                break;
            }
            if(a[i].f>a[r[j+1]].f||b[i].f>b[r[j+1]].f||c[i].f>c[r[j+1]].f)
            {
                cout<<"no\n";
                break;
            }
        }
        if(j==2)
            cout<<"yes\n";
    }
    return 0;
}
