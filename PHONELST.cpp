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

struct node
{
    struct node *num[11];
};

struct node *getnode(void)
{
    struct node *pnode=NULL;
    pnode=(struct node*)malloc(sizeof(struct node));
    if(pnode)
    {
        for(int i=0;i<10;i++)
            pnode->num[i]=NULL;
    }
    return pnode;
}

void in(struct node *root,int *a,int n)
{
    struct node *pcrawl=root;
    int i;
    for(i=0;i<n;i++)
    {
        if(!pcrawl->num[a[i]])
            pcrawl->num[a[i]]=getnode();
        pcrawl=pcrawl->num[a[i]];
    }
}

bool out(struct node *root,int *a,int n)
{
    struct node *pcrawl=root;
    int i,p=0;
    for(i=0;i<n;i++)
    {
        if(!pcrawl->num[a[i]])
            return false;
        pcrawl=pcrawl->num[a[i]];
    }
    for(i=0;i<10;i++)
        if(pcrawl->num[i])
            p++;
    return pcrawl!=NULL&&!p;
}

int m[10004],b[10004][11];
char s[11];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,p,n;
    cin>>t;
    while(t--)
    {
        struct node *root=getnode();
        memset(m,0,sizeof(m));
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s;
            m[i]=strlen(s);
            for(int j=0;j<m[i];j++)
                b[i][j]=(int)(s[j]-'0');
            in(root,b[i],m[i]);
        }
        p=0;
        for(i=0;i<n;i++)
        {
            if(!out(root,b[i],m[i]))
            {
                printf("NO\n");
                break;
            }
            else
                p++;
        }
        if(p==n)
            printf("YES\n");
    }
    return 0;
}
