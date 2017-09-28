#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class arrStack{
	private:
		int m_size;
		int top;
		T *st;
	public:
		arrStack(int size)
		{
			top = -1;
			st = new T[size+1];
			m_size = size + 1;
		}
		arrStack()
		{
			top = -1;
			m_size = 1;
			st = new T[m_size];
		}
		~arrStack()
		{
			delete [] st;
		}
		void clear()
		{
			for(int i = 0; i <= top; i++)
			{
				top--;
				pop();
			}
		}
		bool push(const T item)
		{
			if(top == m_size-1)
			{
				T *new_st = new T[m_size*2];
				if(new_st == NULL)
					return false;
				for(int i = 0; i <= top; i++)
					new_st[i] = st[i];
				m_size *= 2;
				delete [] st;
				st = new_st;
			}
			top++;
			st[top] = item;
			return true;
		}

		bool pop()
		{
			if(top == -1)
				return false;
			top--;
			return true;
		}
		bool find_top(T &item)
		{
			if(top == -1)
				return false;
			item = st[top];
			return true;
		}
		void get_size()
		{
			cout << m_size << endl;
		}
};

template <class T>
class Link{
	private:
		T item;
		Link *next;
	public:
		Link(T item, Link *next)
		{
			this->item = item;
			this->next = next;
		}
		T get_item()
		{
			return item;
		}
		Link* get_next()
		{
			return next;
		}
};


template <class T>
class linkStack{
	private:
		Link<T> *top;
		int size;
	public:
		linkStack()
		{
			top = NULL;
			size = 0;
		}
		~linkStack()
		{
			clear();
		}
				
		bool push(const T item)
		{
			Link<T> *i = new Link<T>(item, top);
			top = i;
			size++;
		}
		bool pop()
		{
			if(size == 0)
				return false;
			Link<T> *tmp = top->get_next();
			delete top;
			top = tmp;
			size--;
			return true;
		}
		bool find_top(T &item)
		{
			if(size == 0)
				return false;
			item = top->get_item();
			return true;
		}
		void clear()
		{
			while(top)
			{
				pop();
			}
		}
	
		void get_size()
		{
			cout << size << endl;
		}
};
		
int main()
{
	linkStack<int> a1;
	a1.get_size();
	a1.push(1);
	a1.get_size();
	a1.clear();
	a1.push(2);
	a1.get_size();
	a1.push(3);
	a1.pop();
	int a;
	a1.find_top(a);
	cout << a << endl;
	return 0;
}
