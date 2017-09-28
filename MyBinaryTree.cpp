#include <iostream>
#include <queue>
using namespace std;

template <class T>
class BinaryTree;

template <class T>
struct BinaryTreeNode{
	T info;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
};

template <class T>
class BinaryTree{
	private:
		BinaryTreeNode<T>* root;
	public:
		BinaryTree() 
		{
			root = new BinaryTreeNode<T>;
			root = create();
		}
		~BinaryTree() {delete_tree(root);}
		BinaryTreeNode<T>* get_root() const {return root;}
		BinaryTreeNode<T>* parent(BinaryTreeNode<T> *t, BinaryTreeNode<T> *c) const
		{
			if(root == t) return NULL;
			if(c->left == t || c->right == t) return c;
			BinaryTreeNode<T> *a, *b;
			a = parent(t->left, c);
			b = parent(t->right, c);
			if(a != NULL) return a;
			if(b != NULL) return b;
			return NULL;
		}	
//		BinaryTreeNode<T>* left_slibing(BinaryTreeNode<T> *current) const;
//		BinaryTreeNode<T>* right_slibing(BinaryTreeNode<T> *current) const;
		BinaryTreeNode<T>* left_child(BinaryTreeNode<T> *current) const {return current->left;}
		BinaryTreeNode<T>* right_child(BinaryTreeNode<T> *current) const {return current->right;}
		BinaryTreeNode<T>* create()
		{
			T c;
			cin >> c;
			if(c == -1)
				return NULL;
			BinaryTreeNode<T>* p = new BinaryTreeNode<T>;
			p->info = c;
			p->left = create();
			p->right = create();
			return p;
		}
		void preorder(BinaryTreeNode<T> *root)
		{
			if(root == NULL) return;
			visit(root);
			preorder(root->left);
			preorder(root->right);
		}
		void inorder(BinaryTreeNode<T> *root)
		{
			if(root == NULL) return;
			inorder(root->left);
			visit(root);
			inorder(root->right);
		}
		void postorder(BinaryTreeNode<T> *root)
		{
			if(root == NULL) return;
			postorder(root->left);
			postorder(root->right);
			visit(root);
		}
		void delete_tree(BinaryTreeNode<T> *root)
		{
			if(root == NULL) return;
			delete_tree(root->left);
			delete_tree(root->right);
			delete root;
		}
		void level_order(BinaryTreeNode<T> *root)
		{
			queue<BinaryTreeNode<T>*> s;
			s.push(root);
			BinaryTreeNode<T> *tmp;
			while(!s.empty())
			{
				tmp = s.front();
				s.pop();
				visit(tmp);
				if(tmp->left != NULL) s.push(tmp->left);
				if(tmp->right != NULL) s.push(tmp->right);
			}
		}
		void visit(BinaryTreeNode<T>* root) {cout << root->info << " ";}
};


int main()
{
	BinaryTree<int> bt;
	bt.preorder(bt.get_root());
	cout << endl;
	bt.level_order(bt.get_root());
	cout << endl;
}
