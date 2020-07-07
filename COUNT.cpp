#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int part[5005][5005];

void par()
{
    int i,j;
    for(i=1;i<=5000;i++)
        part[i][1]=1;
    for(i=1;i<=5000;i++)
    {
        for(j=2;j<=i;j++)
            part[i][j]=(part[i-1][j-1]%1988+part[i-j][j]%1988)%1988;
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i;
    par();
    while(1)
    {
        scanf("%d%d",&n,&k);
        if(!n&&!k)
            break;
        printf("%d\n",part[n][k]);
    }
    return 0;
}
