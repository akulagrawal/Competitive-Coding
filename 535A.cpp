#include<bits/stdc++.h>

using namespace std;

int main()
{
    char a[5];
    int n,p=0;
    gets(a);
    n=strlen(a);
    if(n==2)
    {
    switch(a[0])
    {
        case '2': cout<<"twenty";
                  break;
        case '3': cout<<"thirty";
                  break;
        case '4': cout<<"forty";
                  break;
        case '5': cout<<"fifty";
                  break;
        case '6': cout<<"sixty";
                  break;
        case '7': cout<<"seventy";
                  break;
        case '8': cout<<"eighty";
                  break;
        case '9': cout<<"ninety";
                  break;
        default:  break;
    }
    if(a[0]=='1')
    {
    switch(a[1])
    {
        case '0': cout<<"ten";
                  break;
        case '1': cout<<"eleven";
                  break;
        case '2': cout<<"twelve";
                  break;
        case '3': cout<<"thirteen";
                  break;
        case '4': cout<<"fourteen";
                  break;
        case '5': cout<<"fifteen";
                  break;
        case '6': cout<<"sixteen";
                  break;
        case '7': cout<<"seventeen";
                  break;
        case '8': cout<<"eighteen";
                  break;
        case '9': cout<<"nineteen";
                  break;
        default:  break;
    }
    }
    }
    if(n==2&&a[0]>'1')
    {
        if(a[1]!='0')
            cout<<"-";
        p=1;
    }
    switch(a[p])
    {
        case '0': if(n==1)
                    cout<<"zero";
                  break;
        case '1': if(n==1||p==1)
                    cout<<"one";
                  break;
        case '2': cout<<"two";
                  break;
        case '3': cout<<"three";
                  break;
        case '4': cout<<"four";
                  break;
        case '5': cout<<"five";
                  break;
        case '6': cout<<"six";
                  break;
        case '7': cout<<"seven";
                  break;
        case '8': cout<<"eight";
                  break;
        case '9': cout<<"nine";
                  break;
        default:  break;

    }
    return 0;
}
