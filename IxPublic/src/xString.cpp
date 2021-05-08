#include "xString.h"
#include <cstring>
#include <cstdlib>
namespace IOx
{
	inline void String::rrsize(size_t x)
	{
		if (ssize < x)
			_Bx._ptr = (char*)realloc(_Bx._ptr, x * 2);
	}

	std::ostream& operator<<(std::ostream& out, String& str)
	{
		if (str.length() <= String::String::BUF_LEN-1)
		{
			out << str._Bx._Buf;
		}
		else
		{
			out << str._Bx._ptr;
		}
		return out;
	}

	std::istream& operator>>(std::istream& in, String& str)
	{
		char ch;
		/* size_t oldSize = str.size(); */
		bool hasPrevBlank = false;
		while (in.get(ch))
			if (isblank(ch) || ch == '\n') {
				hasPrevBlank = true;
			}
			else
				break;
		in.putback(ch);
		str.clear();
		while (in.get(ch)) {
			if (ch != EOF && !isblank(ch) && ch != '\n') {
				str += ch;
			}
			else
				break;
		}
		return in;
	}

	std::istream& getline(std::istream& in, String& str, char delim) {
		char ch;
		str.clear();
		while (in.get(ch)) {
			if (ch == delim)
				break;
			else
				str += ch;
		}
		return in;
	}

	std::istream& getline(std::istream& in, String& str) {
		return getline(in, str, '\n');
	}

	inline char& String::operator[](size_t pos)
	{
		if (ssize <= String::BUF_LEN-1)
			return _Bx._Buf[pos];
		else
			return _Bx._ptr[pos];
	}

	inline const char& String::operator[](size_t pos) const
	{
		if (pos >= ssize)
			return '\0';
		else if (ssize <= String::BUF_LEN-1)
			return _Bx._Buf[pos];
		else
			return _Bx._ptr[pos];
	}

	inline const char* String::c_str() const
	{
		if (ssize <= String::BUF_LEN-1)
		{
			return _Bx._Buf;
		}
		else
		{
			return _Bx._ptr;
		}
	}

	int String::compare(const String& str) const
	{
		return strcmp(c_str(), str.c_str());
	}
	int String::compare(const char* s) const
	{
		return strcmp(c_str(), s);
	}

	bool operator==(const String& lhs, const String& rhs)
	{
		return (lhs.compare(rhs) == 0);
	}

	bool operator==(const char* lhs, const String& rhs)
	{
		return (rhs.compare(lhs) == 0);
	}

	bool operator==(const String& lhs, const char* rhs)
	{
		return (lhs.compare(rhs) == 0);
	}

	bool operator!=(const String& lhs, const String& rhs)
	{
		return (lhs.compare(rhs) != 0);
	}

	bool operator!=(const char* lhs, const String& rhs)
	{
		return (rhs.compare(lhs) != 0);
	}

	bool operator!=(const String& lhs, const char* rhs)
	{
		return (lhs.compare(rhs) != 0);
	}

	bool operator<(const String& lhs, const String& rhs)
	{
		return (lhs.compare(rhs) < 0);
	}

	bool operator<(const char* lhs, const String& rhs)
	{
		return (rhs.compare(lhs) >= 0);
	}

	bool operator<(const String& lhs, const char* rhs)
	{
		return (lhs.compare(rhs) < 0);
	}

	bool operator<=(const String& lhs, const String& rhs)
	{
		return (lhs.compare(rhs) <= 0);
	}

	bool operator<=(const char* lhs, const String& rhs)
	{
		return (rhs.compare(lhs) > 0);
	}

	bool operator<=(const String& lhs, const char* rhs)
	{
		return (lhs.compare(rhs) <= 0);
	}

	bool operator>(const String& lhs, const String& rhs)
	{
		return (lhs.compare(rhs) > 0);
	}

	bool operator>(const char* lhs, const String& rhs)
	{
		return (rhs.compare(lhs) <= 0);
	}

	bool operator>(const String& lhs, const char* rhs)
	{
		return (lhs.compare(rhs) > 0);
	}

	bool operator>=(const String& lhs, const String& rhs)
	{
		return (lhs.compare(rhs) >= 0);
	}

	bool operator>=(const char* lhs, const String& rhs)
	{
		return (rhs.compare(lhs) < 0);
	}

	bool operator>=(const String& lhs, const char* rhs)
	{
		return (lhs.compare(rhs) >= 0);
	}

	String& String::operator=(char c)
	{
		if (ssize <= String::BUF_LEN-1)
		{
			memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
			strcpy(_Bx._Buf, (char*)&c);
		}
		else
		{
			memset(_Bx._ptr, 0, ssize);
			strcpy(_Bx._ptr, (char*)&c);
		}
		ssize = 1;
		return *this;
	}

	String& String::operator=(const char* s)
	{
		if (strlen(s) <= String::BUF_LEN-1)
		{
			memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
			strcpy(_Bx._Buf, s);
		}
		else
		{
			rrsize(strlen(s));
			memset(_Bx._ptr, 0, 2 * strlen(s));
			strcpy(_Bx._ptr, s);
		}
		ssize = strlen(s);
		return *this;
	}

	String& String::operator=(const String& str)
	{
		if (ssize <= String::BUF_LEN-1)
		{
			if (str.ssize <= String::BUF_LEN-1)
			{
				memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
				strcpy(_Bx._Buf, str.c_str());
			}
			else
			{
				rrsize(str.ssize);
				strcpy(_Bx._ptr, str.c_str());
			}
		}
		else
		{
			if (str.ssize <= String::BUF_LEN-1)
			{
				delete[] _Bx._ptr;
				memset(_Bx._Buf, 0, sizeof(_Bx._Buf));
				strcpy(_Bx._Buf, str.c_str());
			}
			else
			{
				rrsize(str.ssize);
				memset(_Bx._ptr, 0, ssize);
				strcpy(_Bx._ptr, str.c_str());
			}
		}
		ssize = str.size();
		return *this;
	}

	String& String::operator+=(const char* s)
	{
		size_t len = strlen(s);
		if (len + ssize <= String::BUF_LEN-1)
		{
			strcat(_Bx._Buf, s);
			ssize = strlen(_Bx._Buf);
		}
		else
		{
			if (ssize <= String::BUF_LEN-1)
			{
				ssize += len;
				char* tp = new char[ssize * 2];
				strcpy(tp, _Bx._Buf);
				strcat(tp, s);
				_Bx._ptr = tp;
			}
			else
			{
				ssize += len;
				char* tp = new char[ssize * 2];
				strcpy(tp, _Bx._ptr);
				strcat(tp, s);
				delete[] _Bx._ptr;
				_Bx._ptr = tp;
			}
		}
		return *this;
	}

	String& String::operator+=(char c)
	{
		if (1 + ssize <= String::BUF_LEN-1)
		{
			strcat(_Bx._Buf, (char*)&c);
			ssize++;
		}
		else
		{
			if (ssize <= String::BUF_LEN-1)
			{
				ssize += 1;
				char* tp = new char[ssize * 2];
				strcpy(tp, _Bx._Buf);
				strcat(tp, (char*)&c);
				_Bx._ptr = tp;
			}
			else
			{
				ssize += 1;
				char* tp = new char[ssize * 2];
				strcpy(tp, _Bx._ptr);
				strcat(tp, (char*)&c);
				delete[] _Bx._ptr;
				_Bx._ptr = tp;
			}
		}
		return *this;
	}

	String& String::operator+=(const String& str)
	{
		std::cout << str.length() + ssize << std::endl;
		if (str.length() + ssize <= String::BUF_LEN-1)
		{
			strcat(_Bx._Buf, str.c_str());
			ssize = strlen(_Bx._Buf);
		}
		else
		{
			if (ssize <= String::BUF_LEN-1)
			{
				ssize += str.ssize;
				char* tp = new char[ssize * 2];
				strcpy(tp, _Bx._Buf);
				strcat(tp, str.c_str());
				_Bx._ptr = tp;
			}
			else
			{
				ssize += str.ssize;
				char* tp = new char[ssize * 2];
				strcpy(tp, _Bx._ptr);
				strcat(tp, str.c_str());
				delete[] _Bx._ptr;
				_Bx._ptr = tp;
			}
		}
		return *this;
	}

	String operator+(const String& lhs, const String& rhs)
	{
		String str(lhs);
		str += rhs;
		return str;
	}

	String operator+(const String& lhs, const char* rhs)
	{
		String str(lhs);
		str += rhs;
		return str;
	}

	String operator+(const char* lhs, const String& rhs)
	{
		String str(lhs);
		str += rhs;
		return str;
	}

	String operator+(const String& lhs, char rhs)
	{
		String str(lhs);
		str += rhs;
		return str;
	}

	String operator+(char lhs, const String& rhs)
	{
		String str(&lhs);
		str += rhs;
		return str;
	}

	String::String()
	{
		ssize = 0;
		memset(&_Bx, 0, sizeof(_Bx));
	}

	String::String(const String& str)
	{
		ssize = 0;
		memset(&_Bx, 0, sizeof(_Bx));
		if (str.ssize <= String::BUF_LEN-1)
		{
			strcpy(_Bx._Buf, str.c_str());
		}
		else
		{
			rrsize(str.length());
			strcpy(_Bx._ptr, str.c_str());
		}
		ssize = str.length();
	}

	String::String(const char* s)
	{
		ssize = 0;
		memset(&_Bx, 0, sizeof(_Bx));
		size_t tp = strlen(s);
		if (tp <= String::BUF_LEN-1)
		{
			strcpy(_Bx._Buf, s);
			_Bx._Buf[tp] = '\0';
		}
		else
		{
			rrsize(tp);
			strcpy(_Bx._ptr, s);
			_Bx._ptr[tp] = '\0';
		}
		ssize = tp;
	}

	String::String(size_t n, char c)
	{
		ssize = 0;
		memset(&_Bx, 0, sizeof(_Bx));
		if (n <= String::BUF_LEN-1)
		{
			for (size_t i = 0; i < n; i++)
				_Bx._Buf[i] = c;
		}
		else
		{
			rrsize(n);
			for (size_t i = 0; i < n; i++)
				_Bx._ptr[i] = c;
		}
		ssize = n;
	}

	String::String(const char* s, size_t n)
	{
		ssize = 0;
		memset(&_Bx, 0, sizeof(_Bx));
		if (strlen(s) <= n)
		{
			ssize = strlen(s);
			if (n <= String::BUF_LEN-1)
			{
				strcpy(_Bx._Buf, s);
			}
			else
			{
				rrsize(n);
				strcpy(_Bx._ptr, s);
			}
		}
		else
		{
			if (n <= String::BUF_LEN-1)
			{
				strncpy(_Bx._Buf, s, n);
			}
			else
			{
				rrsize(n);
				strncpy(_Bx._ptr, s, n);
			}
			ssize = n;
		}
	}

	String::String(const String& str, size_t pos, size_t len)
	{
		ssize = 0;
		memset(&_Bx, 0, sizeof(_Bx));
		if (pos > str.ssize)
		{
			ssize = 0;
		}
		else
		{
			if (pos + len > str.ssize)
				ssize = str.ssize - pos;
			else
				ssize = len;

			if (ssize <= String::BUF_LEN-1)
			{
				for (size_t i = 0; i < ssize; i++)
				{
					const char* p = str.c_str() + pos;
					_Bx._Buf[i] = p[i];
				}
				_Bx._Buf[ssize] = '\0';
			}
			else
			{
				rrsize(len + 1);
				const char* p = str.c_str() + pos;
				for (size_t i = 0; i < ssize; i++)
				{
					_Bx._ptr[i] = p[i];
				}
				_Bx._ptr[ssize] = '\0';
			}
		}
	}

	String::~String()
	{
		if (ssize > String::BUF_LEN-1 && _Bx._ptr != nullptr)
		{
			delete[] _Bx._ptr;
		}
	}

	inline  size_t String::length() const noexcept
	{
		return ssize;
	}

	inline  size_t String::size() const noexcept
	{
		return ssize;
	}

	inline void String::clear() noexcept
	{
		if (ssize >= String::BUF_LEN-1)
		{
			delete[] _Bx._ptr;
		}
		memset(&_Bx, 0, sizeof(_Bx));
		ssize = 0;
	}

	inline bool String::empty() const
	{
		if (ssize == 0)
		{
			return true;
		}
		else
			return false;
	}

	String& String::append(const String& str)
	{
		*this += str;
		return *this;
	}
	String& String::append(const char* s)
	{
		*this += s;
		return *this;
	}

	inline String& String::assign(const String& str)
	{
		*this = str;
		return *this;
	}
	inline String& String::assign(const char* s)
	{
		*this = s;
		return *this;
	}

	const char* String::data() const
	{
		if (ssize <= String::BUF_LEN-1)
		{
			return _Bx._Buf;
		}
		else
		{
			return _Bx._ptr;
		}
	}

	inline char& String::at(size_t pos)
	{
		if (pos <= String::BUF_LEN-1)
			return _Bx._Buf[pos];
		else
		{
			return _Bx._ptr[pos];
		}
	}

	inline const char& String::at(size_t pos) const
	{
		if (pos <= String::BUF_LEN-1)
			return _Bx._Buf[pos];
		else
		{
			return _Bx._ptr[pos];
		}
	}

	const char* String::getnext(const char* w)
	{
		size_t wlen = strlen(w);

		char* next1 = new char[wlen + 1];
		int j = 0, k = -1;
		next1[0] = -1;

		while (j < wlen)
		{
			if (k == -1 || w[k] == w[j])
			{
				++k;
				++j;
				next1[j] = k;
			}
			else
			{
				k = next1[k];
			}
		}
		return next1;
	}

	const char* String::fastfind(const String& w)
	{

		int tlen = w.ssize;
		const char* next1 = getnext(w.c_str());

		int i = 0, j = 0;
		while (j < tlen)
		{
			if (i == -1 || w[i] == at(j))
			{
				i++;
				j++;
			}
			else
			{
				i = next1[i];
			}
		}
		if (next1 != NULL)
		{
			delete[] next1;
		}

		if (j == tlen)
		{
			return (char*)&at(i - j);
		}
		else
		{
			return NULL;
		}
	}

	const char* String::find(const String& w) const
	{
		return strstr(c_str(), w.c_str());
	}

	void String::swap(String& str)
	{
		String temp = std::move(*this);
		*this = std::move(str);
		str = std::move(temp);
		//mySwap(*this, str);
	}
}