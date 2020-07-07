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

int a[105],b[105];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,k;
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        i=0;
        k=1;
        while(i<n&&k<=7)
        {
            if(a[i]==k)
                b[k]++;
            else if(a[i]==k+1&&k<7)
            {
                k++;
                i--;
            }
            else break;
            i++;
        }
        if(k!=7)
        {
            printf("no\n");
            continue;
        }
        k--;
        while(i<n&&k>0)
        {
            while(b[k]&&i<n)
            {
                if(a[i]!=k)
                    break;
                b[k]--;
                i++;
            }
            if(b[k])
                break;
            k--;
        }
        if(i<n||b[k])
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
