#include <iostream>

using namespace std;

template <class T>
class MinHeap{
	private:
		T *heap_arr;
		int current_size;
		int max_size;
		void build_heap();
	public:
		MinHeap(const int n)
		{
			heap_arr = new T[n];
			max_size = n;
			current_size = 0;
		}
		~MinHeap() {delete heap_arr;}
		bool is_leaf(const int pos)
		{
			if(pos*2+1 < current_size)
				return false;
			return true;
		}
		int left_child(const int pos) {return pos*2+1;}
		int right_child(const int pos) {return pos*2+2;}
		int get_parent(const int pos) {return (pos-1)/2;}
		bool insert(const T &item)
		{
			if(max_size == current_size) return false;
			heap_arr[current_size] = item;
			current_size++;
			sift_up(current_size-1);
			return true;
		}
		void remove_min()
		{
			heap_arr[0] = heap_arr[current_size-1];
			current_size--;
			sift_down(0);
		}
		T get_min() {return heap_arr[0];}
		void sift_up(const int pos)
		{
			if(pos == 0) return;
			int p = get_parent(pos);
			if(heap_arr[pos] < heap_arr[p])
			{
				T tmp = heap_arr[pos];
				heap_arr[pos] = heap_arr[p];
				heap_arr[p] = tmp;
				sift_up(p);
				return;
			}
			return;
		}		
		void sift_down(const int pos)
		{
			if(is_leaf(pos)) return;
			int l = left_child(pos);
			int r = right_child(pos);
			if(heap_arr[l] < heap_arr[r] && heap_arr[l] < heap_arr[pos])
			{
				T tmp = heap_arr[pos];
				heap_arr[pos] = heap_arr[l];
				heap_arr[l] = tmp;
				sift_down(l);
				return;
			}
			if(heap_arr[r] < heap_arr[l] && heap_arr[r] < heap_arr[pos])
			{
				T tmp = heap_arr[pos];
				heap_arr[pos] = heap_arr[r];
				heap_arr[r] = tmp;
				sift_down(r);
				return;
			}
			return;
		}
};

/*
int main()
{
	MinHeap<int> mh(10);
	mh.insert(5);
	mh.insert(2);
	mh.insert(3);
	mh.insert(1);
	mh.remove_min();
	cout << mh.get_min() << endl;
}
*/
