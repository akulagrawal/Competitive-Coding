#include<bits/stdc++.h>
using namespace std;

typedef struct file{
    string fi;
    struct file* ptr;
} file;

typedef struct folder{
    string fo;
    file *front1, *end1;
    struct folder *ptr;
} folder;

file* getfile(string w)
{
    file *temp=NULL;
    temp=new file;
    temp->fi=w;
    temp->ptr=NULL;
    return temp;
}

folder* getfolder(string w)
{
    folder *temp=NULL;
    temp=new folder;
    temp->fo=w;
    temp->front1=temp->end1=NULL;
    temp->ptr=NULL;
    return temp;
}

folder* newfo(folder *top, string s)
{
    folder *temp=getfolder(s);
    temp->ptr=top;
    if(top!=NULL)
        cout<<"Made "<<s<<" in "<<top->fo<<endl;
    top=temp;
    return top;
}

void createfi(folder *top,string s)
{
    file *temp = getfile(s);
    cout<<"Created "<<s<<" in "<<top->fo<<endl;
    if(top->front1==NULL)
    {
        top->front1=top->end1=temp;
        return;
    }
    (top->front1)->ptr=temp;
    top->front1 = temp;
}

void deletefi(folder* top)
{
    if(top->end1==NULL)
    {
        cout<<"Cannot delete from "<<top->fo<<endl;
        return;
    }
    cout<<"Deleted "<<(top->end1)->fi<<" from "<<top->fo<<endl;
    file *temp=top->end1;
    top->end1=(top->end1)->ptr;
    if(top->end1==NULL)
        top->front1=NULL;
    delete temp;
}

folder* backfo(folder* top)
{
    if(top->ptr==NULL)
    {
        cout<<"Cannot back from root"<<endl;
        return top;
    }
    folder *temp=top;
    cout<<"Back from "<<top->fo<<endl;
    top=top->ptr;
    while(temp->end1!=NULL)
    {
        file* end2=temp->end1;
        temp->end1=(temp->end1)->ptr;
        delete(end2);
    }
    delete(temp);
    return top;
}

int main()
{
    folder *top=NULL;
    top=newfo(top,"root");
    string s,p;
    while(1)
    {
        cin>>s;
        if(s=="NEW")
        {
            cin>>p;
            top=newfo(top,p);
        }
        else if(s=="CREATE")
        {
            cin>>p;
            createfi(top,p);
        }
        else if(s=="DELETE")
            deletefi(top);
        else if(s=="BACK")
            top=backfo(top);
        else
        	break;
    }
    return 0;
}
