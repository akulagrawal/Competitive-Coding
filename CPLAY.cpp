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
    char s[25];
    int i,n,p;
    while(scanf("%s",&s)!=EOF)
    {
        n=strlen(s);
        p=0;
        if(n!=20)
            break;
        for(i=0;i<20;i+=2)
        {
            p+=(int)(s[i]=='1')-(int)(s[i+1]=='1');
            if(i<=8&&2*abs(p)>8-i)
            {
                if(p>0)
                {
                    printf("TEAM-A ");
                    if(s[i+1]=='1'||2*p>10-i)
                        printf("%d\n",i+1);
                    else
                        printf("%d\n",i+2);
                }
                else
                {
                    printf("TEAM-B ");
                    if((s[i]=='0'&&s[i+1]=='0')||(2*p<i-10))
                        printf("%d\n",i+1);
                    else
                        printf("%d\n",i+2);
                }
                break;
            }
            else if(i>8&&p!=0)
            {
                if(p>0)
                    printf("TEAM-A");
                else
                    printf("TEAM-B");
                printf(" %d\n",i+2);
                break;
            }
        }
        if(i==20)
            printf("TIE\n");
    }
    return 0;
}
