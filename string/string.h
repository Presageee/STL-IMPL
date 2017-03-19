#pragma once
#pragma warning(disable:4996)
#include "common.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
namespace lib
{
	class string
	{
	public:
		string()
		{
			memset(b_data, '\0', sizeof(char) * 16);
			len = 0;
		}

		string(const char* str)
		{
			memset(b_data, '\0', sizeof(char) * 16);
			int str_len = strlen(str);
			if (str_len > 15)
			{
				type = HEAP;
				init(str_len);
				strcpy(data, str);
			}
			else
			{
				strcpy(b_data, str);
			}
			this->len = str_len;
		}

		string(const string &s)
		{
			memset(b_data, '\0', sizeof(char) * 16);
			if (s.type == STACK)
			{
				strcpy(b_data, s.b_data);
			}
			else
			{
				if (data == NULL)
				{
					init(s.len);
				}
				strcpy(data, s.data);
				type = HEAP;
			}
			len = s.len;
		}

		~string()
		{
			if (data)
			{
				delete[] data;
				data = nullptr;
			}
		}

		friend string operator +(string &str, const string &str2)
		{
			string nStr(str);
			if (nStr.expanison(str2.len))
			{
				if (str2.type == STACK)
				{
					memcpy(nStr.data + nStr.len, str2.b_data, sizeof(char) * str2.len);
					nStr.len += str2.len;
				}
				else
				{
					memcpy(nStr.data + nStr.len, str2.data, sizeof(char) * str2.len);
					nStr.len += str2.len;
				}
			}
			else
			{
				memcpy(nStr.b_data + nStr.len, str2.b_data, sizeof(char) * str2.len);
				nStr.len += str2.len;
			}
			return nStr;
		}



		void append(const string &str)
		{
			if (expanison(str.len))
			{
				if (str.type == STACK)
				{
					memcpy(this->data + this->len, str.b_data, sizeof(char) * str.len);
					this->len += str.len;
				}
				else
				{
					memcpy(this->data + this->len, str.data, sizeof(char) * str.len);
					this->len += str.len;
				}
			}
			else
			{
				memcpy(this->b_data + this->len, str.b_data, sizeof(char) * str.len);
				this->len += str.len;
			}
		}

		inline int length()
		{
			return this->len;
		}

		friend std::ostream &operator<<(std::ostream &o, const string &str)
		{
			if (str.type == STACK)
			{
				o << str.b_data;
			} 
			else
			{
				o << str.data;
			}
			return o;
		}
	private:
		inline bool inHead()
		{
			if (data == NULL)
			{
				return R_OK;
			}
			else
			{
				return R_ERR;
			}
		}

		inline void init(int size)
		{
			char* t_data = new char[size + 1];
			memset(t_data, '\0', (size + 1) * sizeof(char));
			if (data)
			{
				memcpy(t_data, data, sizeof(char) * len);
				delete[] data;
			}
			data = t_data;
//			this->type = HEAP;
		}

		inline int expanison(int size)
		{
			int destLen = len + size;
			if (destLen > 15)
			{
				init(destLen);
				if (type == STACK)
				{
					memcpy(data, b_data, sizeof(char) * len);
					memset(b_data, '\0', 16 * sizeof(char));
				}
				this->type = HEAP;
				return R_OK;
			}
			return R_ERR;
		}
	
		char b_data[16];
		char* data = nullptr;
		TYPE type = STACK;
		int len = 0;
	};
}//end of lib