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

bool isvo(char ch)
{
	return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int i;
    bool p=0;
    for(i=1;i<s.size();i++)
    {
    	if(!isvo(s[i-1])&&(s[i-1]!='n'))
    		p=p|(!isvo(s[i]));
    }
    if(p)
    	cout<<"NO";
    else if(s.size()==1&&(isvo(s[0])||s[0]=='n'))
    	cout<<"YES";
    else if(s.size()==1)
    	cout<<"NO";
    else if(!isvo(s[s.size()-1])&&s[s.size()-1]!='n')
        cout<<"NO";
    else
    	cout<<"YES";

    return 0;
}