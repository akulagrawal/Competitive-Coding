#include<bits/stdc++.h>
using namespace std;
bool prime[10000001];

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
   /* for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";*/
}


int main()
{
   int a,b;

   SieveOfEratosthenes(10000001);
   scanf("%d%d",&a,&b);

   int i,lpf1,lpf2;
    for (i = 1; i <=a; i++)
        if (prime[i] && a % i == 0)
            lpf1 = i;

    for (i = 1; i <=b; i++)
        if (prime[i] && b % i == 0)
            lpf2 = i;

    int x,y,c=0,d=0;
    x=a;
    y=b;
    while(x%lpf1==0)
    {
        x=x/lpf1; c++;
    }

    while(y%lpf2==0)
    {
       y=y/lpf2; d++;
    }



   return 0;
}
