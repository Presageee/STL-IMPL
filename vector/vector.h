#pragma once
#include "NoCopy.h"
#include "common.h"
namespace lib {
template<class T>class vector {
public:
	vector()
	{
		id = 0;
		init(0);
	}
	
	vector(int len)
	{
		init(len);
	}

	vector(const vector<T>* v, int size, int id)
	{
		if (v->index < size) 
		{
			size = v->index;
		}
		init(size);
		this->index = size;
		this->id = id;
		memcpy(this->buff, v->buff, sizeof(T) * size);
	}

	~vector()
	{
		if (buff != NULL)
		{
			delete[]buff;
			buff = NULL;
		}
		cout << "destory id - >" << id << endl;
	}

	void remove(int index) 
	{
		if (index >= this->index)
		{
			throw new std::exception("index of -1");
		}
		T& t = buff[index];
		memmove(buff + index, buff + index + 1, sizeof(T) * (this->index - index));
		this->index--;
	}

	T& removeItem(int index) 
	{
		if (index >= this->index)
		{
			throw new std::exception("index of -1");
		}
		T& t = buff[index];
		// 1 2 3 4 5
		// 1 2 3 5
		// 0 1 2 3 4
		memmove(this->buff + index, this->buff + index + 1, sizeof(T) * (this->index - index));
		this->index--;
		return t;
	}

	int insert(const T& t, int index)
	{
		if (index >= len)
		{
			return R_ERR;
		}
		if (index + 1 == len)
		{
			expansion();
		}
		memmove(this->buff + index + 1, this->buff + index, (this->index - index) * sizeof(T));
		buff[index] = t;
		this->index++;
		return index;
	}

	void add(const T& v)
	{
		if (index == len)
		{
			expansion();
		}
		buff[index++] = v;
	}

	int find(const T t)
	{
		for (int i = 0; i < index; i++)
		{
			if (buff[i] == t)
			{
				return i;
			}
		}
	}

	T& get(int index) 
	{
		if (index > this->index) {
			throw new std::exception("index of -1");
		}
		return buff[index];
	}
	
	//vector* operator ->()
	//{
	//	return &this;
	//}

	T& operator [](int index)
	{
		if (index >= 0 && index <= this->index) 
		{
			return buff[index];
		}
	}

	inline int size()
	{
		return index;
	}

private:
	inline void init(int size)
	{
		len = size > 0 ? size : 0;
		index = 0;
		if (len == 0)
		{
			buff = NULL;
		}
		else
		{
			buff = new T[len];
			memset(buff, 0, sizeof(T) * len);
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
		if (buff != NULL)
		{
			memcpy(newBuff, buff, sizeof(T) * index);
			delete []buff;
		}
		buff = newBuff;
	}
	int len;
	int index;
	T* buff;
	int id;
};

}//end of lib