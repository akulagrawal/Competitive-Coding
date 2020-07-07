#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,i;
    scanf("%d",&n);
    k=n/2;
    printf("%d\n",k);
    if(n%2==0)
    {
        for(i=0;i<k-1;i++)
            printf("2 ");
        printf("2");
    }
    else
    {
        for(i=0;i<k-1;i++)
            printf("2 ");
        printf("3");
    }
    return 0;
}
