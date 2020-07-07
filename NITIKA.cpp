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
    int t,n,p,i,j;
    char s[50];
    scanf("%d",&t);
    getchar();
    for(j=0;j<t;j++)
    {
        p=0;
        scanf("%[^\n]s",&s);
        getchar();
        n=strlen(s);
        s[0]=toupper(s[0]);
        printf("%c",s[0]);
        for(i=1;i<n;i++)
        {
            if(s[i]==' ')
                p++;
        }
        i=1;
        while(p>0)
        {
            if(s[i-1]==' ')
            {
                p--;
                s[i]=toupper(s[i]);
                printf(". %c",s[i]);
            }
            i++;
        }
        for(;i<n;i++)
        {
            s[i]=tolower(s[i]);
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
