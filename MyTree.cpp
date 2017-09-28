#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Tree;

template <class T>
struct treeNode{
	T info;
	treeNode<T> *most_lchild;
	treeNode<T> *rsibling;
};

template <class T>
class Tree{
	private:
		treeNode<T>* root;
	public:
		Tree() 
		{
			root = new treeNode<T>;
			root = create();
		}
		~Tree() {delete_tree(root);}
		treeNode<T>* get_root() const {return root;}
		treeNode<T>* parent(treeNode<T> *t, treeNode<T> *c) const
		{
			if(root == t) return NULL;
			if(c->most_lchild == t || c->rsibling == t) return c;
			treeNode<T> *a, *b;
			a = parent(t->most_lchild, c);
			b = parent(t->rsibling, c);
			if(a != NULL) return a;
			if(b != NULL) return b;
			return NULL;
		}	
//		treeNode<T>* most_lchild_slibing(treeNode<T> *current) const;
//		treeNode<T>* rsibling_slibing(treeNode<T> *current) const;
		treeNode<T>* most_lchild_child(treeNode<T> *current) const {return current->most_lchild;}
		treeNode<T>* rsibling_child(treeNode<T> *current) const {return current->rsibling;}
		treeNode<T>* create()
		{
			T c;
			cin >> c;
			if(c == -1)
				return NULL;
			treeNode<T>* p = new treeNode<T>;
			p->info = c;
			p->most_lchild = create();
			p->rsibling = create();
			return p;
		}
		void preorder(treeNode<T> *root)
		{
			if(root == NULL) return;
			visit(root);
			preorder(root->most_lchild);
			preorder(root->rsibling);
		}
		void inorder(treeNode<T> *root)
		{
			if(root == NULL) return;
			inorder(root->most_lchild);
			visit(root);
			inorder(root->rsibling);
		}
		void postorder(treeNode<T> *root)
		{
			if(root == NULL) return;
			postorder(root->most_lchild);
			postorder(root->rsibling);
			visit(root);
		}
		void delete_tree(treeNode<T> *root)
		{
			if(root == NULL) return;
			delete_tree(root->most_lchild);
			delete_tree(root->rsibling);
			delete root;
		}
		void level_order(treeNode<T> *root)
		{
			queue<treeNode<T>*> s;
			s.push(root);
			treeNode<T> *tmp;
			while(!s.empty())
			{
				tmp = s.front();
				s.pop();
				visit(tmp);
				if(tmp->most_lchild != NULL) s.push(tmp->most_lchild);
				if(tmp->rsibling != NULL) s.push(tmp->rsibling);
			}
		}
		void visit(treeNode<T>* root) {cout << root->info << " ";}
};


int main()
{
	Tree<int> bt;
	bt.preorder(bt.get_root());
	cout << endl;
	bt.level_order(bt.get_root());
	cout << endl;
}
