#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

typedef struct fib{
    int val;
    int degree;
    struct fib* parent;
    struct fib* child;
    struct fib* left;
    struct fib* right;
    bool mark;
}* hp;

hp createlist(hp heap[],int n,int idx)              //Create function of fibonacci heap , list with 1 element
{
        hp temp= new fib;
        temp->val=n;
        temp->degree=0;
        temp->mark=0;
        temp->parent=NULL;
        temp->child=NULL;
        temp->left=temp;
        temp->right=temp;
        heap[idx]=temp;
        return temp;
}

hp insertnode(hp heap[],int n,int idx)      //Inserting node in circular list
{
        hp temp= new fib;
        temp->val=n;
        temp->degree=0;
        temp->parent=NULL;
        temp->child=NULL;
        hp a=heap[idx]->left;
        a->right=temp;
        heap[idx]->left=temp;
        temp->right=heap[idx];
        temp->left=a;
        if(n<heap[idx]->val)
            heap[idx]=temp;
}

int union1(hp min1[],int num[],int i,int j)            //Union function if two heaps are to be merged
{
        hp a=min1[i];
        hp b=min1[j];
        hp c=a->left;
        hp d=b->left;
        c->right=b;
        d->right=a;
        a->left=d;
        b->left=c;
        if(a->val>b->val)
        {
            min1[i]=b;
            num[i]=num[i]+num[j];
            num[j]=-1;
            return i+1;
        }
        num[j]=num[j]+num[i];
        num[i]=-1;
        return j+1;
}

void heap_link(hp min1[],hp a,hp b)                   //function to link b and a and make b the child of a
{
        hp c=b->left;
        hp d=b->right;
        c->right=d;
        d->left=c;
        b->left=b;
        b->right=b;
        if(a->child==NULL)                  //Make b a's child
        {
            a->child=b;
            a->degree+=1;
        }
        else                                //concatenate b in child list of a
        {
            a->degree+=1;
            hp p=a->child;
            hp q=p->left;
            q->right=b;
            p->left=b;
            b->right=p;
            b->left=q;
            b->parent=a;
        }
}

void extract_min(hp min1[],int i,int z)               //Extract min function to remove the smallest element in the heap and print it if flag is on
{
          hp c1;
          if(min1[i]->left!=min1[i])                        //Take out a and merge its children with the root list
          {
            hp a1=min1[i];
            c1=a1->left;
            hp d1=a1->right;
            min1[i]=c1;
            c1->right=d1;
            d1->left=c1;
            hp b=a1->child;
            if(z==1)
                cout<<"Extracted Values is : "<<a1->val<<endl;
            free(a1);
            if(b!=NULL)
            {
                hp c=b;
                do
                {                                                 //Take out a and merge its children with the root list
                    hp t=c->right;
                    c->parent=NULL;
                    hp a=c1->left;
                    a->right=c;
                    c1->left=c;
                    c->right=c1;
                    c->left=a;
                    c=t;
                }while(c!=b);
            }
          }
            else                                        //If only one element then create a new root list
            {
               if(z==1) cout<<"Extracted Values is : "<<min1[i]->val<<endl;
                c1=min1[i]->child;
                hp c=c1;
                hp b=c1;
                free(min1[i]);
                min1[i]=c1;
                do
                {
                    c->parent=NULL;
                    c=c->right;
                }while(c!=b);
            }

            int maxdegree=0;                            //Find node with max degree
             hp c=c1;
             hp b=c1;
            min1[i]=c1;
            do
            {
                if(maxdegree<c->degree)maxdegree=c->degree;
                if(min1[i]->val>c->val)min1[i]=c;
                c=c->right;
            }while(c!=b);
            hp arr[maxdegree+100];                          //Make array of pointer of maxdegree +100
            for(int j=0;j<maxdegree+100;j++)
                arr[j]=NULL;
            c=min1[i];
            b=min1[i];
            int p=0;
            do
            {
                hp t=c->right;
                int d=c->degree;
                while(arr[d]!=NULL)
                {
                    hp y=arr[d];
                    if(y->val<c->val)
                        {
                            hp t=y;
                            y=c;
                            c=t;
                        }
                    heap_link(min1,c,y);
                    arr[d]=NULL;
                    d++;
                }
                arr[d]=c;
                c=t;
                p++;
            }while(c!=b);
            min1[i]=NULL;
            for(int j=0;j<maxdegree+100;j++)                        //use the consolidate array to reconstruct the heap
            {
                if(arr[j]!=NULL)
                {
                    if(min1[i]==NULL)
                    {
                        min1[i]=arr[j];
                        arr[j]->left=arr[j];
                        arr[j]->right=arr[j];
                    }
                    else
                    {
                        hp a=min1[i]->left;
                        a->right=arr[j];
                        min1[i]->left=arr[j];
                        arr[j]->right=min1[i];
                        arr[j]->left=a;
                        if(arr[j]->val<min1[i]->val)min1[i]=arr[j];
                    }
                }
            }
}


int num_nodes(struct fib* c1)                       //Number of nodes in list of a
{
    hp c=c1;
    hp b=c1;
    int i=0;
    do
    {
        i++;
        c=c->right;
    }while(b!=c);
    return i;
}

void showheap(struct fib *x,int depth)                       //recursive function to print fibonacci heap
{
    struct fib *temp=x;
    int i,j,k;
    k=num_nodes(temp);                                     //k is no .of elements in list of x that will be used to traverse full list
    for(i=0;i<k;i++)
    {
        for(j=0;j< 9*(depth); j++)     //depth increases as with increase in successors
        {
            printf(" ");
        }
        printf("   %d",x->val);
        if(x->child!=NULL)              //traversing down till last successor of root element
        {
            printf("\n");
            showheap(x->child,depth+1);    // depth increases by 1 as successor increases
        }
        else
        {
            printf("\n\n");
        }
        x=x->right;                       //next element
    }
}

void menu()                                 // display menu
{
    cout<<"         OPERATION               |PRESS KEY\n";
    cout<<"MAKE-FIB-HEAP                    |   c\n";
    cout<<"FIB-HEAP-UNION                   |   u\n";
    cout<<"FIB-HEAP-INSERT                  |   i\n";
    cout<<"FIB-HEAP-EXTRACT-MIN             |   e\n";
    cout<<"PRINT-HEAP                       |   S\n";
    cout<<"Turn off Print after extract min |   +\n";
    cout<<"Turn on print after extract min  |   -\n";
    cout<<"QUIT                             |   q\n";
}

int main()
{
    char c;
    hp min1[MAX];                       // min1[i] points to the minimum element (head) of the (i+1)th fibonacci heap
    int num[MAX];                       // num[i] contains no. of elements in (i+1)th heap
    for(int j=0;j<MAX;j++)
        num[j]=-1;
    int p=0;
    int i=-1;
    menu();                                     //no of elements
    while(1)
    {
        cout<<"Enter choice : ";
        cin>>c;
        switch(c)
        {
            case 'c':{
                        i++;
                        num[i]=0;
                        createlist(min1,0,i);
                        cout<<"Created Heap "<<i+1<<"\n";
                        break;
                    }
            case 'u':{
                        if(i<1)
                            cout<<"Very few heaps to take union\n";
                        else
                        {
                            cout<<"Enter heap no.(starting from 1) to take union : \n";
                            int x,y;
                            cin>>x>>y;
                            if(x>i+1||x<1||y>i+1||y<1)
                                cout<<"Invalid indices\n";
                            else
                                cout<<"Union made at "<<union1(min1,num,x-1,y-1)<<endl;
                        }
                        break;
                    }
            case 'i':{
                        if(i>=0&&!num[i])
                        {
                            cout<<"Enter element : ";
                            int x;
                            cin>>x;
                            min1[i]->val=x;
                            num[i]=1;
                        }
                        else if(i<0)
                            cout<<"No Heap\n";
                        else if(i>=0)
                        {
                            cout<<"Enter element : ";
                            int x;
                            cin>>x;
                            insertnode(min1,x,i);
                            num[i]++;
                        }
                        break;
                    }
            case 'e':{
                        if(num[i]>1)
                        {
                            extract_min(min1,i,p);
                            num[i]--;
                        }
                        else if(num[i]==1)
                        {
                            num[i]=0;
                            if(p)
                                cout<<"Extracted Values is : "<<min1[i]->val<<endl;
                        }
                        else if(i<0)
                            cout<<"No Heap to extract\n";
                        else
                            cout<<"Empty Heap\n";
                        break;
                    }
            case 'S':{
                        if(num[i]==0)
                            cout<<"Empty Heap\n";
                        else if(num[i]<0)
                            cout<<"No heap";
                        else
                            showheap(min1[i],0);
                        break;
                    }
            case 'q': exit(0);
            case '+':{                              // if print flag is on, p=1 otherwise p=0
                        p=1;
                        cout<<"Print flag : on\n";
                        break;
                    }
            case '-':{
                        p=0;
                        cout<<"Print flag : off\n";
                        break;
                    }
            default : cout<<"Invalid input\n";
        }
    }
    return 0;
}
