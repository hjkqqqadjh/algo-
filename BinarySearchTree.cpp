#include <iostream>
//本树是反的

using namespace std;

template <class T>
class BST;

template <class T>
struct BSTNode{
		T info;
		BSTNode<T>* left;
		BSTNode<T>* right;
};

template <class T>
class BST{
	private:
		BSTNode<T> *root;
	public:
		BST() {root = NULL;}
	//	~BST();
		BSTNode<T>* get_root() {return root;}
		BSTNode<T>* search(const T &item, BSTNode<T> *current)
		{
			if(current == NULL) return NULL;
			if(current->info = item) return current;
			if(current->info < item)
				return search(item, current->left);
			else
				return search(item, current->right);
		}
		void insert(const T &item, BSTNode<T> *current)
		{
			if(root == NULL)
			{
				root = new BSTNode<T>;
				root->info = item;
				root->left = root->right = NULL;
				return;
			}
			if(current->info < item && current->left != NULL)
				insert(item, current->left);
			else if(current->info < item && current->left == NULL)
			{
				current->left = new BSTNode<T>;
				current->left->info = item;
				current->left->left = current->left->right = NULL;
			}
			else if(current->info > item && current->right != NULL)
				insert(item, current->right);
			else
			{
				current->right = new BSTNode<T>;
				current->right->info = item;
				current->right->left = current->right->right = NULL;
			}
		}
		BSTNode<T>* min_node(BSTNode<T>* current)
		{
			if(current == NULL) return NULL;
			if(current->left != NULL) return min_node(current->left);
			else return current;
		}
		BSTNode<T>* get_parent(const T &item, BSTNode<T>* root)
		{
			if(root == NULL) return NULL;
			cout << root->info << " ";
			if(item > root->info && root->left)
			{
				if(root->left->info == item) return root;
				return get_parent(item, root->left);
			}
			else if(item < root->info && root->right)
			{
				if(root->right->info == item) return root;
				return get_parent(item, root->right);
			}
			else return NULL;
		}
		
		BSTNode<T>* max_node(BSTNode<T>* current)
		{
			if(current == NULL) return NULL;
			if(current->right != NULL) return max_node(current->right);
			else return current;
		}
		void remove_tree(BSTNode<T>* root);
		void remove_node(BSTNode<T>* current, BSTNode<T>* root);
};

int main()
{
	BST<int> bst;
	bst.insert(2, bst.get_root());
	bst.insert(1, bst.get_root());
	bst.insert(3, bst.get_root());
	bst.insert(5, bst.get_root());
	bst.insert(0, bst.get_root());
	bst.insert(9, bst.get_root());
//	bst.remove_tree(bst.search(1, bst.get_root()));
	cout << bst.get_parent(0, bst.get_root()) << endl;
	cout << bst.search(3, bst.get_root())->info << endl;
}
