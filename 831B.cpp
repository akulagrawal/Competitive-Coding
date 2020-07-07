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

map<char,char> my;

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int i;
    for(i=0;i<26;i++)
    {
        my[s1[i]]=s2[i];
        my[toupper(s1[i])]=toupper(s2[i]);
    }
    for(i=0;i<s3.size();i++)
    {
        if((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z'))
            cout<<my[s3[i]];
        else
            cout<<s3[i];
    }
    return 0;
}
