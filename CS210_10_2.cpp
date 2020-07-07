#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10004
#define mod 1000000007

int hl(char s[],ll pow[],int i)                 // hash function
{
	return ((ll)(s[i]-'a'+1)*pow[i])%mod;
}

void calc(ll pow[],int p)               // make array pow[], pow[i] stores p raised to the power i taken modulo mod
{
    pow[0]=1;
    for(int i=1;i<MAX;i++)
        pow[i]=(pow[i-1]*(ll)p)%mod;
}

void hash_insert(ll h[],char s[],ll pow[])      // hash string s in hash array h, h[i] is hash of substring 1..i
{
	h[0]=0;
	int n=strlen(s);
    for(int i=0;i<n;i++)
        h[i+1]=(h[i]+(ll)hl(s,pow,i))%mod;
}

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output1.out","w",stdout);
    char s1[MAX],s2[MAX];
    ll hashs1[MAX],hashs2[MAX],p,q,q2;          // hashs1[] stores hash of string 1 and hashs2[] stores hash of string 2
    ll pow1[MAX];
    int i,a,b,n,m,t,k;
    calc(pow1,31);                  // store and calculate powers of 31. 31 is chosen because it is a prime no. between 26 and 52
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        m=strlen(s2);
        hash_insert(hashs2,s2,pow1);        // hash of string to be deleted is calculated and stored in hashs2[]
        do{
        k=0;
        n=strlen(s1);
        hash_insert(hashs1,s1,pow1);    // calculate hash of remaining string in every loop
        q=hashs2[m];
        for(a=1;a<=n-m+1;a++)
        {
            s1[a-k-1]=s1[a-1];              // k denotes no. of letters removed. Thus, copy current letter at position k elements before current position
            b=a+m-1;
            p=(hashs1[b]-hashs1[a-1]+mod)%mod;  // finding hash of substring from a to b by subtracting hash of substring from 1 to a from that of 1 to b
            q2=(q*pow1[a-1])%mod;               // since there is a an increase of a factor of 31 with increase in index, balance it before comparing
                                                // by multiplying hash of string to be removed by pow[difference in starting indices of substring (a-1)]
            if(p==q2)
            {
                int check=0;
                for(i=a-1;i<b;i++)          // checking for collisions and confirming equality
                {
                    if(s1[i]==s2[i-a+1])
                        check++;
                }
                if(check==m)            // if substring is same as string to be removed, jump to the letter after the substring
                {                       // and increment letters deleted by size of substring i.e. m
                    k+=m;
                    a=b;
                }
            }
        }
        for(;a<=n;a++)
            s1[a-k-1]=s1[a-1];
        s1[a-k-1]='\0';
        }while(strlen(s1)<n);               // stop when there is no occurrence of string to be deleted
        cout<<s1<<endl;
    }
    return 0;
}
