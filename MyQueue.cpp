#include <iostream>

using namespace std;

template <class T>
class linkQueue;

template <class T>
class arrQueue{
	private:
		int m_size;
		int front;
		int rear;
		T *qu;
	public:
		arrQueue(int sz = 10)
		{
			m_size = sz + 1;
			front = 1;
			rear = 0;
			qu = new T[m_size];
		}
		~arrQueue()
		{
			delete [] qu;
		}
		bool en_queue(const T item)
		{
			if(length() == m_size-1)
				return false;
			rear = (rear + 1) % m_size;
			qu[rear] = item;
			return true;
		}
		bool de_queue()
		{
			if(length() == 0)
				return false;
			front = (front + 1) % m_size;
			return true;
		}
		int length()
		{
			return (rear-front+1+m_size)%m_size;
		}
		bool get_front(T &item)
		{
			if(length() == 0)
				return false;
			item = qu[front];
			return true;
		}
};

template <class T>
class Link{
	friend class linkQueue<T>;
	private:
		T item;
		Link* next;
	public:
		Link(T it, Link* n)
		{
			item = it;
			next = n;
		}
		T get_value()
		{
			return item;
		}
		Link* get_next()
		{
			return next;
		}
};


template <class T>
class linkQueue{
	private:
		Link<T> *front;
		Link<T> *rear;
		int size;
	public:
		linkQueue()
		{
			front = rear = NULL;
			size = 0;
		}
		~linkQueue()
		{
			clear();
		}
		void en_queue(const T item)
		{
			if(rear == NULL)
				front = rear = new Link<T>(item, NULL);
			else
			{
				rear->next = new Link<T>(item, NULL);
				rear = rear->get_next();
			}
			size++;
		}
		bool de_queue()
		{
			if(size == 0)
				return false;
			Link<T> *tmp = front;
			front = front->get_next();
			delete tmp;
			size--;
			if(size == 0)
				rear = NULL;
			return true;
		}
		void clear()
		{
			while(size != 0)
				de_queue();
		}
		bool get_front(T &item)
		{
			if(size == 0)
				return false;
			item = front->get_value();
			return true;
		}
		void get_size()
		{
			cout << size << endl;
		}
};


int main()
{
	linkQueue<int> a1;
	a1.en_queue(1);
	a1.en_queue(2);
	a1.get_size();
	a1.en_queue(3);
	a1.en_queue(4);
	a1.de_queue();
	a1.clear();
	a1.get_size();
	a1.en_queue(5);
	int a;
	a1.get_front(a);
	cout << a << endl;
	return 0;
}

