#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 505
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int a[MAX][MAX];

int main()
{
    int t,n,i,j,sum,temp;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j])
                    sum++;
            }
        }
        temp=-1*n;
        for(i=0;i<n;i++)
        {
            temp+=2*(n-i);
            if(temp>=sum)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

    return 0;
}
