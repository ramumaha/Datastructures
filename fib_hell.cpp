#include<bits/stdc++.h>
using namespace std;

template <class V> class Fibonacci;

template <class V> struct node{
private:
    node<V>*prev;
    node<V>*next;
    node<V>*child;
    node<V>*parent;
    V value;
    int degree;
    bool marked;
public:
    friend class Fibonacci<V>;
};

template<class V> class Fibonacci{
protected:
    node<V>*heap;
public:
    Fibonacci(){
        heap=_empty();
    }
    node<V>* insert(V val){
        node<V>*ret=_singleton(val);
        heap=_merge(heap,ret);
        return ret;
    }

    void merger(Fibonacci &other){
        heap=_merge(heap,other.heap);
        other.heap=_empty();
    }

    bool isempty(){
        return heap==NULL;
    }

    V getminimum(){
        return heap->value;
    }

    V removemin(){
        node<V>*old=heap;
        heap=_removeminimum(heap);
        V ret=old->value;
        delete old;
        return ret;
    }

    void display(){
        node<V>*p=heap;
        if(p==NULL){
            cout<<"Heap is empty\n";
            return;
        }
        cout<<"The roots in the heap : \n";
        _display_tree(heap,"");
        cout<<"\n";
    }
    bool isEmpty() {
		return heap==NULL;
	}

private:
    node<V>* _empty(){
        return NULL;
    }
    node<V>* _singleton(V val){
        node<V>*n=new node<V>;
        n->value=val;
        n->prev=n->next=n;
        n->degree=0;
        n->marked=0;
        n->child=NULL;
        n->parent=NULL;
        return n;
    }

    node<V>* _merge(node<V>*a,node<V>*b){
         if(a==NULL)return b;
         if(b==NULL)return a;
        if(a!=NULL){
            (a->prev)->next=b;
            b->next=a;
            b->prev=a->prev;
            a->prev=b;
            if(b->value<a->value){
                a=b;
            }
        }
        return a;
    }

    void _addchild(node<V>*parent,node<V>*child){
        child->prev=child->next=child;
        child->parent=parent;
        parent->degree++;
        parent->child=_merge(parent->child,child);//welcome to club
    }

    void _unmarkandunparent(node<V>*n){//extract min. child of min become parent so unmark
        if(n==NULL)
            return;
        node<V>*c=n;
        do{
            c->marked=0;
            c->parent=NULL;
            c=c->next;
        }while(c!=n);

    }

    node<V>* _removeminimum(node<V>* n) {
        //display();
		if(n->next==n) {
			n=n->child;
		} else {
			n->prev->next=n->next;
            n->next->prev=n->prev;
            if(n->degree==0)
            {   //cout<<"deg1";
                n=n->next;
                n=_merge(n->child,n->next);
            }
            //cout<<n->next->value<<"is val\n";
			else{
                n=_merge(n->child,n->next);
                 n=n->next;
            }
            //cout<<n->value<<"is val\n";            
		}
        if(n==NULL)return n;
		node<V>* trees[64]={NULL};
 
		while(true) {
			if(trees[n->degree]!=NULL) {
				node<V>* t=trees[n->degree];
				if(t==n)break;
				trees[n->degree]=NULL;
				t->prev->next=t->next;
				t->next->prev=t->prev;
				if(n->value<t->value) {
					_addchild(n,t);
				} else {
					if(n->next==n) {
						t->next=t->prev=t;
					} else {
						n->prev->next=t;
						n->next->prev=t;
						t->next=n->next;
						t->prev=n->prev;
					}
					_addchild(t,n);
					n=t;
				}
				continue;
			} else {
				trees[n->degree]=n;
			}
			n=n->next;
		}
		node<V>* min=n;
		do {
			if(n->value<min->value)min=n;
			n=n->next;
		} while(min!=n);
		return min;
	}

   void  _display_tree(node<V>*n,string pre) const{
      string pc = "│  ";
		node<V>* x = n;
		do {
			if (x->next != n) {
				cout << pre << "├─";
			} else {
				cout << pre << "└─";
				pc = "   ";
			}
			if (x->child == nullptr) {
				cout << "─" << x->value << endl;
			} else {
				cout << "┐" << x->value << endl;
				_display_tree(x->child, pre + pc);
			}
			//		cout << endl;
			x = x->next;
		} while (x != n);
	} 

};

int main()
{
    Fibonacci<int> f;
    f.insert(53);
    f.insert(2);
     f.insert(33);
     f.insert(50);
    f.insert(5);
     f.insert(69);
    f.insert(71);
    f.insert(64);
     f.insert(54);
     f.insert(11);
     f.insert(99);
    f.display();
    while(f.isEmpty()!=1)
    {
        cout<<f.removemin()<<" is the minimum removed\n ";
        cout<<"\n";
        f.display();
    }
}