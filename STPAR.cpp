#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define INF 1000005
#define pii pair<int,int>

int main()
{
    //freopen ("input1.in","r",stdin);
    //freopen ("output22.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x;
    while(1)
    {
        scanf("%d",&n);
        if(!n)
            break;
        stack<int> my1,my2;
        my1.push(0);
        while(n--)
        {
            scanf("%d",&x);
            if(x==my1.top()+1)
                my1.push(x);
            else
                my2.push(x);
            while(!my2.empty()&&(my2.top()==my1.top()+1))
            {
                x=my2.top();
                my2.pop();
                my1.push(x);
            }
        }
        if(!my2.empty())
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
