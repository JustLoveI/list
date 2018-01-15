#ifndef __MHEAP__H
#define __MHEAP__H
#endif

int max(int a, int b) { return  a > b ? a : b; }

template <class T>
class heap
{
public:
	heap(){ m_start = 0; m_finish = 0; m_end_of_storage = 0; }
	typedef T value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	typedef size_t size_type;
	typedef size_t Distance;
	typedef value_type& reference;

	iterator m_start;
	iterator m_finish;
	iterator m_end_of_storage;

	iterator begin(){ return m_start; }
	const_iterator begin()const{ return m_start; }
	iterator end(){ return m_finish; }
	const_iterator end()const{ return m_finish; }
	reference operator[](size_type __n) { return *(begin() + __n); }
	void destroy(iterator &begin)
	{
		delete[]begin;
	}

	size_type size() const{ return size_type(end() - begin()); }
	size_type capacity() const{ return size_type(m_end_of_storage - begin()); }


	void allocate(int n)
	{
		const size_type old_size = size();
		const size_type len = old_size + max(old_size, n);

		iterator new_start = new value_type[len];
		iterator new_finish = new_start;

		for (pointer ii = m_start; ii != m_finish; ii++)
		{
			*new_finish = *ii;
			new_finish++;
		}
		destroy(m_start);

		m_start = new_start;
		m_finish = new_finish;
		m_end_of_storage = new_start + len;

	}
	void push_back(const T &item)
	{
		if (m_finish + 1 > m_end_of_storage)
			allocate(1);
		*m_finish = item;
		m_finish++;
		push_heap(m_start, size() - 1, 0, *(m_finish - 1));
	}

	//向上回溯到topIndex维护一条支线
	void push_heap(iterator first, Distance holeIndex, Distance topIndex, T value)
	{
		Distance parent = (holeIndex - 1) / 2;
		//父亲节点序号小于当前节点序号 并且 父亲节点值小于当前节点值
		while (topIndex < holeIndex && value > *(first + parent))
		{
			*(first + holeIndex) = *(first + parent);
			holeIndex = parent;
			parent = (holeIndex - 1) / 2;
		}
		*(first + holeIndex) = value;
	}

	//建立一个堆

	void make_heap()
	{
		iterator first = m_start;
		iterator last = m_finish;
		if (last - first < 2) return;
		Distance parent = (last - first) / 2;

		while (true)
		{
			adjust_heap(first, parent, last - first, *(first + parent));
			out();
			if (parent == 0) break;
			parent--;
			
			
		}
	}
	void sort()
	{
		iterator first = m_start;
		iterator last = m_finish;
		while (last - first > 1)
		{
			__pop_heap(first, last , last - 1);
			last--;
			out();
		}
	}
	void __pop_heap(iterator first, iterator last, iterator result)
	{
		T value = *(last - 1);
		*result = *first;
		adjust_heap(first, 0, (last - first) - 1, value);
	}

	//维护以first为顶的大顶堆
	void adjust_heap(iterator first, Distance holeIndex, Distance len/*heap堆内元素个数*/, T value)
	{
 		Distance topIndex = holeIndex;

		Distance secondChild = 2 * (holeIndex + 1);
		while (secondChild < len)
		{
			if (*(first + secondChild) < *(first + secondChild - 1))
				secondChild--;
			*(first + holeIndex) = *(first + secondChild);
 			holeIndex = secondChild;
			secondChild = 2 * (holeIndex + 1);
		}
		if (secondChild == len)
		{
			*(first + holeIndex) =  *(first + secondChild - 1);
			holeIndex = secondChild - 1;
		}
		push_heap(first, holeIndex, topIndex, value);
	}
	void out()
	{
		for (iterator ii = m_start; ii < m_finish; ii++)
		{
			printf("%d ", *ii);
		}
		printf("\n");
	}
};