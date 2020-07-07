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

int lps[MAX];
int ans[MAX];

void makeLPS(string s)
{
    int n=s.size(),i=1,j=0;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            lps[i]=j;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,p;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        p=0;
        n=s1.size();
        m=s2.size();
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (s2[j] == s1[i])
            {
                j++;
                i++;
            }
            if (j == m)
            {
                ans[p]=i-j+1;
                p++;
                j = lps[j-1];
            }
            else if (i < n && s2[j] != s1[i])
            {
                if (j != 0)
                    j = lps[j-1];
                else
                    i = i+1;
            }
        }
        if(p)
        {
            printf("%d\n",p);
            for(i=0;i<p;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
        if(!p)
            printf("Not Found\n");
        printf("\n");
    }
    return 0;
}
