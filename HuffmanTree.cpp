#include <iostream>
#include "BinaryHeap.cpp"

using namespace std;

template <class T>
class huffmanNode{
	public:
		int weight;
		T element;
		huffmanNode<T> *left, *right;
		bool operator < (huffmanNode<T> h2)
		{
			if(this->weight < h2.weight) return true;
			return false;
		}
		bool operator > (huffmanNode<T> h2)
		{
			if(this->weight > h2.weight) return true;
			return false;
		}
};

template <class T>
class huffmanTree{
	private:
		huffmanNode<T> *root;
	public:
		void merge_tree(huffmanNode<T> *h1, huffmanNode<T> *h2, huffmanNode<T> *parent)
		{
			parent->weight = h1->weight + h2->weight;
			parent->left = h1;
			parent->right = h2;
		}
//	public:
		huffmanTree(huffmanNode<T> nodes[], int n)
		{
			MinHeap<huffmanNode<T> > heap(n);
			huffmanNode<T> *parent, *lchild, *rchild;
			huffmanNode<T> *node_list = new huffmanNode<T>[n];
			for(int i = 0; i < n; i++)
			{
				node_list[i].element = nodes[i].element;
				node_list[i].weight = nodes[i].weight;
				node_list[i].left = node_list[i].right = NULL;
				heap.insert(node_list[i]);
			}
			for(int i = 1; i < n; i++)
			{
				parent = new huffmanNode<T>;
				lchild = new huffmanNode<T>;
				rchild = new huffmanNode<T>;
				*lchild = heap.get_min();
				heap.remove_min();
				*rchild = heap.get_min();
				heap.remove_min();
				merge_tree(lchild, rchild, parent);
				heap.insert(*parent);
				root = parent;
			}
			delete [] node_list;
		}
	//	~huffmanTree();
	void traverse(huffmanNode<T>* h)
	{
		if(h->left == NULL && h->right == NULL) cout << h->element << endl;
		if(h->left != NULL) traverse(h->left);
		if(h->right != NULL) traverse(h->right);
		return;
	}
	huffmanNode<T>* get_root() {return root;}
};

int main()
{
	huffmanNode<char> h[5];
	for(int i = 0; i < 5; i++)
	{
		h[i].weight = i;
		h[i].element = 'a' + i;
	}
	huffmanTree<char> ht(h, 5);
	cout << ht.get_root()->right->right->left->weight << endl;
//	ht.traverse(ht.get_root());
}

