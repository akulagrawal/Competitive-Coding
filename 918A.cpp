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
    int n,a=1,b=1,c=2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i==a)
        {
            cout<<"O";
            a=b;
            b=c;
            c=a+b;
            if(a==1)
            {
                a=b;
            b=c;
            c=a+b;
            }
        }
        else
            cout<<"o";
    }
    return 0;
}
