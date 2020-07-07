#include<bits/stdc++.h>

using namespace std;

typedef struct binst{
	int num;
	struct binst *l;
	struct binst *r;
	struct binst *par;
	int h;
} bst;

bst* getnode(int n)
{
	bst *temp=NULL;
	temp=new bst;
	temp->num=n;
	temp->l=temp->r=temp->par=NULL;
	temp->h=0;
	return temp;
}

int hdif(bst *t)
{
    if(t->l==NULL&&t->r==NULL)
        return 0;
    if(t->l==NULL)
        return -1*(t->r->h+1);
    if(t->r==NULL)
        return t->l->h+1;
    return t->l->h-t->r->h;
}

bst* rotr(bst *t)
{
    bst *temp=t->l->r;
    t->l->r=t;
    t->l->par=NULL;
    t->par=t->l;
    t->l=temp;
    if(t->l==NULL&&t->r==NULL)
        t->h=0;
    else if(t->r==NULL)
        t->h=t->l->h+1;
    else if(t->l==NULL)
        t->h=t->r->h+1;
    else
        t->h=max(t->l->h,t->r->h)+1;
    t->par->h=max(t->par->h,t->h+1);
    return t->par;
}

bst* rotl(bst *t)
{
    bst *temp=t->r->l;
    t->r->l=t;
    t->r->par=NULL;
    t->par=t->r;
    t->r=temp;
    if(t->l==NULL&&t->r==NULL)
        t->h=0;
    else if(t->l==NULL)
        t->h=t->r->h+1;
    else if(t->r==NULL)
        t->h=t->l->h+1;
    else
        t->h=max(t->r->h,t->l->h)+1;
    t->par->h=max(t->par->h,t->h+1);
    return t->par;
}

bst* rotlr(bst *t)
{
    t=rotr(t);
    t->par=rotl(t->par);
    return t->par;
}

bst* rotrl(bst *t)
{
    t=rotl(t);
    t->par=rotr(t->par);
    return t->par;
}

bst* balance(bst *root  ,bst *t)
{
    bst *temp=t;
    int p,q;
    while(temp!=NULL)
    {
        p=0;
        q=0;
        p=hdif(temp);
        if(temp->par!=NULL)
            q=hdif(temp->par);
        if(p<-1)
        {
            if(q>1)
                temp->par=rotrl(temp->par);
            else
                temp=rotl(temp);
        }
        else if(p>1)
        {
            if(q>1)
                temp->par=rotlr(temp->par);
            else
                temp=rotr(temp);
        }
        if(temp->par==NULL)
            root=temp;
        temp=temp->par;
    }
    return root;
}

bst* bst_insert(bst *root,int n)
{
	bst *temp=NULL;
	temp=getnode(n);
	cout<<n<<" is inserted\n";
	if(root==NULL)
		return root=temp;
	bst *x=NULL, *y=NULL;
	x=root;
	while(x!=NULL)
	{
		x->h++;
		y=x;
		if(n<=y->num)
			x=x->l;
		else
			x=x->r;
	}
	temp->par=y;
	temp->h=y->h-1;
	if(n<=y->num)
		y->l=temp;
	else
        y->r=temp;
    root=balance(root,temp);
	return root;
}

bst* bst_search(bst *root,int n)
{
	if(root==NULL||n==root->num)
		return root;
	if(n<=root->num)
		return bst_search(root->l,n);
	return bst_search(root->r,n);
}

bst* bst_min(bst *x)
{
	bst *y=NULL;
	while(x!=NULL)
	{
		y=x;
		x=x->l;
	}
	return y;
}

bst* bst_successor(bst *x)
{
	return bst_min(x->r);
}

bst* bst_delete(bst *root,int n)
{
	bst *x=NULL,*y=NULL,*z=NULL;
	x=bst_search(root,n);
	if(x==NULL)
	{
		cout<<n<<" cannot be deleted\n";
		return root;
	}
	if(x->l==NULL||x->r==NULL)
		y=x;
	else
		y=bst_successor(x);
	if(y->l!=NULL)
		z=y->l;
	else
		z=y->r;
	if(z!=NULL)
		z->par=y->par;
	if(y->par!=NULL)
	{
		if(y==(y->par)->l)
			(y->par)->l=z;
		else
			(y->par)->r=z;
	}
	else
		root=z;
	x->num=y->num;
	root=balance(root,y->par);
	delete(y);
	cout<<n<<" is deleted\n";
	return root;
}

void print_inorder(bst *root)
{
	if(root==NULL)
		return;
	cout<<root->num<<" ";
	print_inorder(root->l);

	print_inorder(root->r);
}

int main()
{
	string s;
	int n;
	bst *root=NULL;
	while(1)
	{
		cin>>s;
		if(s=="-1")
			break;
		if(s=="INSERT")
		{
			cin>>n;
			root=bst_insert(root,n);
		}
		else if(s=="SEARCH")
		{
			cin>>n;
			bst *x=NULL;
			x=bst_search(root,n);
			if(x==NULL)
				cout<<n<<" is not found\n";
			else
				cout<<n<<" is found\n";
		}
		else if(s=="DELETE")
		{
			cin>>n;
			root=bst_delete(root,n);
		}
		else cout<<"WRONG CHOICE\n";
	}
	cout<<"Inorder: ";
	print_inorder(root);
	cout<<endl;
	return 0;
}
