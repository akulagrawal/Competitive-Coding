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

typedef struct node{
    string s;
    int f;
    struct node *l, *r;
} node;

node* getnode(int freq,string w)
{
    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));
    temp->s=w;
    temp->f=freq;
    temp->l=temp->r=NULL;
    return temp;
}

struct compare
{
    bool operator()(const node* l, const node* r)
    {
        if(l->f!=r->f)
            return l->f > r->f;
        else
            return l->s > r->s;
    }
};

node* merge2(node *a,node *b)
{
    node *temp=NULL;
    temp=getnode(a->f+b->f,a->s+b->s);
    temp->l=a;
    temp->r=b;
    return temp;
}

node* build(int freq[])
{
    int i,j,minm=300,ch;
    priority_queue< node*, vector<node*> , compare > pq;
    string w;
    node *root=NULL, *x=NULL, *y=NULL;
    for(i=0;i<256;i++)
    {
        if(freq[i])
        {
            w=i;
            pq.push(getnode(freq[i],w));
        }
    }
    while(pq.size()!=1)
    {
        x=pq.top();
        pq.pop();
        y=pq.top();
        pq.pop();
        root=merge2(x,y);
        pq.push(root);
    }
    return root;
}

void print(node *root, string w, string ans[])
{
    if(root==NULL)
        return;
    if(root->l==NULL&&root->r==NULL)
    {
        ans[root->s[0]]=w;
        return;
    }
    print(root->l,w+"0",ans);
    print(root->r,w+"1",ans);
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,ans[257];
    int n,i;
    int freq[257];
    node *root=NULL;
    for(i=0;i<256;i++)
        freq[i]=0;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
        freq[(int)s[i]]++;
    root=build(freq);
    print(root,"",ans);
    for(i=0;i<n;i++)
    {
        if(freq[(int)s[i]])
        {
            freq[(int)s[i]]=0;
            cout<<s[i]<<"="<<ans[s[i]]<<" ";
        }
    }
    return 0;
}
