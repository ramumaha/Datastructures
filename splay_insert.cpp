#include<iostream>
#include<string>
#include<stack>

using namespace std;

template<class x>
class splaytree;

template<class x>
class node
{
    x element;
    node<x> *left;
    node<x> *right;
public:
    node(x c):element(c),left(NULL),right(NULL){}
    friend class splaytree<x>;
};

template<class x>
class splaytree
{
    node<x> *root;
protected:
    int leaf(node<x> *k)
    {
        if(k->left==NULL && k->right==NULL)
            return 1;
        return 0;
    }
    void rightrotate(node<x> **t)
    {
        node<x>*k=(*t)->left;
        (*t)->left=k->right;
        k->right=(*t);
        (*t)=k;
    }
    void leftrotate(node<x> **t)
    {
        node<x>*k=(*t)->right;
        (*t)->right=k->left;
        k->left=(*t);
        (*t)=k;
    }
    void splay(x c,node<x> **k)
    {
        if((*k)==NULL || (*k)->element==c)return;
        if((*k)->element>c)
        {
            if((*k)->left==NULL)return;
            if((*k)->left->element>c)
            {
                splay(c,&((*k)->left->left));
                if(leaf((*k))==0)
                    rightrotate(k);
            }
            else if((*k)->left->element<c)
            {
                splay(c,&((*k)->left->right));
                if((*k)->left->right!=NULL)
                    leftrotate(&((*k)->left));
            }
            if((*k)->left!=NULL)
                rightrotate(k);

        }
        else if((*k)->element<c)
        {
            if((*k)->right==NULL)return;
            if((*k)->right->element<c)
            {
                splay(c,&((*k)->right->right));
                if(leaf((*k))==0)
                    leftrotate(k);
            }
            else if((*k)->right->element>c)
            {
                splay(c,&((*k)->right->left));
                if((*k)->right->left!=NULL)
                    rightrotate(&((*k)->right));
            }
            if((*k)->right!=NULL)
                leftrotate(k);
        }

    }
    void insertnode(x c,node<x> **k)
    {
        node<x> *temp;
        temp=new node<x>(c);
        splay(c,k);
        if((*k)->element>c)
        {
            temp->right=(*k);
            temp->left=(*k)->left;
            (*k)->left=NULL;
            (*k)=temp;
        }
        else if((*k)->element<c)
        {
            temp->left=(*k);
            temp->right=(*k)->right;
            (*k)->right=NULL;
            (*k)=temp;
        }
    }
    void searcher(x &temp,node<x> *k,x c)
    {
        if(k!=NULL || temp==c)
        {
            temp=c;
            if(k->element>c)
                searcher(temp,k->left,c);
            else if(k->element<c)
                searcher(temp,k->right,c);
        }
    }
    void maxnode(node<x> *t, node<x> **k)
    {
        if(t!=NULL)
        {
            (*k)= maxnode(t->right,k);
        }
    }
    void minnode(node<x> *t, node<x> **k)
    {
        if(t!=NULL)
        {
            (*k)= minnode(t->left,k);
        }
    }
public:
    splaytree(){root=NULL;}
    void inserter(x c)
    {
        if(root==NULL)
        {
            root=new node<x>(c);
            return;
        }
        insertnode(c,&root);
    }
    void searchnode(x c)
    {
        int temp=INT8_MIN;
        searcher(temp,&root,c);
        if(c==temp)
            cout<<"Element found\n";
        else
            cout<<"Element not found\n";
        splay(temp,&root);
    }
    void preorder()
    {
        node<x> *temp=root;
        stack<node<x>*> k;
        k.push(temp);
        while(!(k.empty()))
        {
            temp=k.top();
            k.pop();
            cout<<temp->element<<endl;
            if(temp->right!=NULL)
            {
                k.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                k.push(temp->left);
            }
        }
    }
};

int main()
{
    splaytree<int> t;int a[]={1, 5, 2, 6, 3, 7, 4, 8};
    for(int i=0;i<8;i++)
    {
        t.inserter(a[i]);
        cout<<"After insertion: \n";t.preorder();
    }
}