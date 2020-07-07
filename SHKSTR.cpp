#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100006
#define mod 1000000007
#define pb push_back
#define INF 1e18
#define pii pair<int,int>

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    int isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key,int idx)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = idx;
}

// Returns true if key presents in trie, else
// false
int search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    if (pCrawl != NULL && pCrawl->isEndOfWord)
        return pCrawl->isEndOfWord;
    return 0;
}


bool cmp(pair<pair<int,string>, int> a, pair<pair<int,string>, int> b)
{
    return a.f.f<b.f.f;
}

string s[MAX];
pair<pair<int,string>, int> my[MAX];
string ans[MAX],mins[MAX];

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    struct TrieNode *root = getNode();

    int i;
    for(i=0;i<n;i++)
        cin>>s[i];

    mins[0]=s[0];

    for(i=1;i<n;i++)
        mins[i]=min(mins[i-1],s[i]);

    int q;
    cin>>q;
    int r;
    string p;

    for(i=0;i<q;i++)
    {
        cin>>my[i].f.f>>my[i].f.s;
        my[i].s=i;
    }
    sort(my,my+q,cmp);
    int j;
    int x=0;
    for(i=0;i<n;i++)
    {
        string k;
        for(j=0;j<s[i].size();j++)
        {
            k+=s[i][j];
            int idx=search(root, k)-1;
            if(idx<0||(s[idx]>s[i]))
                insert(root,k,i+1);
        }
        while((i+1)==my[x].f.f)
        {
            string g=my[x].f.s;
            string s2,l;
            for(int h=0;h<g.size();h++)
            {
                l+=g[h];
                int idx=search(root, l);
                if(idx>0)
                    s2=s[idx-1];
            }
            if(s2=="")
                s2=mins[my[x].f.f-1];
            ans[my[x].s]=s2;
            x++;
        }
    }
    for(i=0;i<q;i++)
        cout<<ans[i]<<endl;
    return 0;
}
