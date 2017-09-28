#include <iostream>

using namespace std;

template <class T>
class parTreeNode{
	public:
		T value;
		parTreeNode<T> *parent;
		int count;
}

template <class T>
class parTree{
	public:
		parTreeNode<T>* array;
		int size;
		parTree(const int size)
		{
			array = new parTreeNode<T>* [size];
			this->size = size;
		}
		parTreeNode<T>* Find(parTreeNode<T>* node) const
		{
			if(node->parent == NULL) return node;
			node->parent = Find(node->parent);
			return node->parent;
		}
		void Union(int i, int j)
		{
			parTreeNode<T>* pi = Find(array[i]);
			parTreeNode<T>* pj = Find(array[j]);
			if(pi == pj) return;
			if(pi->count > pj->count)
			{
				pj->parent = pi;
				pi->count += pj->count;
			}
			else
			{
				pi->parent = pj;
				pj->count += pi->count;
			}
		}
		bool Different(int i, int j);
};

int main()
{
}
