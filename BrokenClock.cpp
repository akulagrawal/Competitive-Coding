#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a;
    char b[10],c[10];
    scanf("%d%s",&a,b);
    if(b[3]>'5')
        b[3]='0';
    if(a==24)
    {
        if((b[0]>'2')||((b[0]=='2')&&(b[1]>'3')))
            b[0]='0';
    }
    else
    {
        if((b[0]=='0')&&(b[1]=='0'))
            b[0]='1';
        else if(b[0]>'0')
        {
            if((b[0]=='1')&&(b[1]<='2'))
            {

            }
            else if(b[1]>'0')
            {
                b[0]='0';
            }
            else
            {
                b[0]='1';
            }
        }
    }
    printf("%s",b);
    return 0;
}
