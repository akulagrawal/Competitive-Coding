#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
#define mod 1000000007

ll hl(char s[],ll pow[],int i)                 // hash function
{
	return ((ll)(s[i]-'a'+1)*pow[i])%mod;
}

void calc(ll pow[],int p)           // make array pow[], pow[i] stores p raised to the power i taken modulo mod
{
    pow[0]=1;
    for(int i=1;i<MAX;i++)
        pow[i]=(pow[i-1]*(ll)p)%mod;
}

void hash_insert(ll h[],char s[],ll pow[])      // hash string s in hash array h, h[i] is the hash of substring 1..i
{
	h[0]=0;
	int n=strlen(s);
    for(int i=0;i<n;i++)
        h[i+1]=(h[i]+hl(s,pow,i))%mod;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output1.out","w",stdout);
    char s[MAX];
    ll hashs1[MAX],p,q;
    ll pow1[MAX];
    int i,a,b,c,d,n,t;
    calc(pow1,31);                          // 31 is chosen because it is a prime no. between 26 and 52
    cin>>s;
    hash_insert(hashs1,s,pow1);             // hashs1[i] stores hash of substring from 1 to i
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        p=(hashs1[b]-hashs1[a-1]+mod)%mod;      // finding hash of substring from a to b by subtracting hash of substring from 1 to a from that of 1 to b
        q=(hashs1[d]-hashs1[c-1]+mod)%mod;      // similarly finding hash of substring from c to d
        if(c>=a)
            p=(p*pow1[c-a])%mod;                // since there is a an increase of a factor of 31 with increase in index, balance it before comparing
        else                                    // by multiplying the smaller index hash by 31 raised to power of the difference in starting indices of substrings
            q=(q*pow1[a-c])%mod;
        if(p==q)
        {
            int check=0;
            for(i=a-1;i<b;i++)                  // check for collisions and confirm the equality
            {
                if(s[i]==s[i+c-a])
                    check++;
            }
            if(check==b-a+1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
