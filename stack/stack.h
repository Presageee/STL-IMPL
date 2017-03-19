#pragma once
#include <stdio.h>
namespace lib
{
	template <class T>
	class stack
	{
	public:
		//stack()
		//{
		//	init(0);
		//}

		stack(int size = 0)
		{
			init(size);
		}

		stack(const stack& s)
		{
			this->len = s.len;
			this->index = s.index;
			this->data = new T[len];
			memset(this->data, 0, sizeof(T) * len);
			memcpy(this->data, s.data, sizeof(T) * index);
		}

		~stack()
		{
			if (data)
			{
				delete[]data;
				data = nullptr;
			}
		}

		T* top()
		{
			if (index == 0)
			{
				return NULL;
			}
			return &data[index - 1];
		}

		T pop()
		{
			T t = data[--index];
			return t;
		}

		bool empty()
		{
			return index == 0 ? true : false;
		}

		int size()
		{
			return index;
		}

		void push(T& t)
		{
			if (index == len)
			{
				expansion();
			}
			data[index++] = t;
		}
	private:

		inline void init(int size)
		{
			len = size > 0 ? size : 0;
			index = 0;
			if (len == 0)
			{
				data = NULL;
			}
			else
			{
				data = new T[len];
				memset(data, 0, sizeof(T) * len);
			}
		}

		inline void calcLength(int size = 0)
		{
			int nLen = len * 3 / 2 + 1;
			if (nLen > len + size)
			{
				len = nLen;
			}
			else
			{
				len = nLen + size;
			}
		}

		void expansion(int size = 0)
		{
			calcLength(size);
			T* newBuff = new T[len];
			memset(newBuff, 0, sizeof(T) * len);
			if (data != NULL)
			{
				memcpy(newBuff, data, sizeof(T) * index);
				delete[]data;
			}
			data = newBuff;
		}

		T* data;
		int index;
		int len;
	};
}//end of lib