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

int ch_int(char ch)         // convert alphabets to integers from 0 to 26
{
    return ch-'a';
}

void topSort(int v, bool vis[30], bool is[30][30], int seq[30],int &m)  // topological sort( dec. order graph for which if there is edge between i and j, is[i][j]=1)
{
    vis[v]=1;
    int i;
    for(i=0;i<26;i++)
    {
        if(is[v][i]&&!vis[i])
            topSort(i,vis,is,seq,m);
    }
    seq[m]=v;
    m++;
}

int main()
{
    string s[102];
    bool is[30][30];        // array in which is[i][j]=1 when i comes before j in atleast 1 word and 0 otherwise
    int seq[30];
    bool vis[30];
    int i,j,k,n,m;
    cin>>n;
    for(i=0;i<26;i++)
        for(j=0;j<26;j++)
            is[i][j]=0;     // initially assign 0 to all elements in 2D is array
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        m=s[i].size();
        for(j=0;j<m;j++)
        {
            for(k=j+1;k<m;k++)
                is[ch_int(s[i][j])][ch_int(s[i][k])]=1;     // checking all combinations in a word and make is[i][j]=1 where i and j are int mapping
        }                                                   // of characters appearing before and after respectively
    }
    m=0;
    for(i=0;i<30;i++)
    {
        seq[i]=0;
        vis[i]=0;
    }
    for(i=0;i<26;i++)
        if(!vis[i])
            topSort(i, vis, is, seq, m);            // topological sorting
                                                    // seq stores the corresponding int value of alphabets such that all alphabets after seq[i]
                                                    //either appear before it in all words or don't appear
    for(i=0;i<26;i++)
    {
        for(j=i+1;j<26;j++)
        {
            if(is[seq[i]][seq[j]])
            {
                cout<<"Impossible";                 // if a character has to appear both before and after some character, then it's impossible.
                return 0;
            }
        }
    }
    cout<<"Possible";
    return 0;
}
