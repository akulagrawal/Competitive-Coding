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

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            result = result*value;
        value = value*value;
        power /= 2;
    }
    return result;
}

const int ALPHABET_SIZE = 2;

// trie node
struct TrieNode
{
    struct TrieNode *children[2];

    int minm;
    int maxm;
    int maxn;
    int minn;
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;
    pNode->minm=MAX;
    pNode->minn=MAX;
    pNode->maxn=0;
    pNode->maxm=0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, int key,int pos)
{
    struct TrieNode *pCrawl = root;
    int t=18;
    ll k;
    while(t--)
    {
        k=fast_pow(2,t);
        if(k>=key)
        {
            key-=k;
            int index = 1;
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
            pCrawl->maxm=max(pCrawl->maxm,pos);
            pCrawl->minm=min(pCrawl->minm,pos);
            pCrawl->maxn=max(pCrawl->maxm,key);
            pCrawl->minn=min(pCrawl->minm,key);
        }
        else
        {
            int index = 0;
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
            pCrawl->maxm=max(pCrawl->maxm,pos);
            pCrawl->minm=min(pCrawl->minm,pos);
            pCrawl->maxn=max(pCrawl->maxm,key);
            pCrawl->minn=min(pCrawl->minm,key);
        }
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
ll search(struct TrieNode *root, int key,int x,int l,int r)
{
    struct TrieNode *pCrawl = root;
    struct TrieNode *temp=root;
    int t=18,flag;
    ll k,ans=0;
    while(t--)
    {
        k=fast_pow(2,t);
        if(k>=key)
        {
            key-=k;
            int index=0;
            flag=0;
            if (!pCrawl->children[index])
                flag=1;
            else
            {
                pCrawl = pCrawl->children[index];
                if(((pCrawl->minn>(x-ans-k))||pCrawl->maxn<key)||(pCrawl->minm>r||pCrawl->maxm<l))
                    flag=1;
                else
                    ans+=k;
            }
            if(flag)
                index=1;
            if (!temp->children[index])
                return 0;
            pCrawl=temp->children[index];
            temp=pCrawl;
            if((pCrawl->minn>key||pCrawl->maxn<key)||(pCrawl->minm>r||pCrawl->maxm<l))
                return 0;
        }
        else
        {
            int index=1;
            flag=0;
            if (!pCrawl->children[index])
                flag=1;
            else
            {
                pCrawl = pCrawl->children[index];
                if((pCrawl->minn>key||pCrawl->maxn<key)||(pCrawl->minm>r||pCrawl->maxm<l))
                    flag=1;
            }

            if((pCrawl->minm>r||pCrawl->maxm<l)||flag)
                index=0;
            else
                ans+=k;
            if (!temp->children[index])
                return 0;
            pCrawl=temp->children[index];
            temp=pCrawl;
        }
    }

    return ans;
}

int keys[MAX];
// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    int n,q,i,l,r,x,y;
    cin>>n>>q;
    for(i=0;i<n;i++)
        cin>>keys[i];
    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i], i+1);

    while(q--)
    {
        cin>>l>>r>>x>>y;
        cout<<search(root, y, x, l, r)<<endl;
    }
    return 0;
}
