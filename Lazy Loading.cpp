#include<bits/stdc++.h>

using namespace std;

int w[102];

int main()
{
    //freopen("lazy_loading.txt","r",stdin);
    //freopen("AKUL4.txt","w",stdout);
    int t,n,i,j,k,p,sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&w[j]);
        printf("Case #%d: ",i);
        sort(w,w+n);
        k=0;
        j=n-1;
        while(j>=k)
        {
            p=50/w[j];
            if(50%w[j]==0)
                p--;
            j--;
            k+=p;
            sum++;
        }
        if((k-j)>1)
            sum--;
        printf("%d\n",sum);
    }
    return 0;
}
