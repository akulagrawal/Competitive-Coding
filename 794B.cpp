#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
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
    double h,a,n,i=1;
    scanf("%lf%lf",&n,&h);
    a=h/sqrt(n);
    while(1)
    {
        printf("%.20lf ",a*sqrt(i));
        i=i+1;
        if(i==n)
            break;
    }
    return 0;
}
