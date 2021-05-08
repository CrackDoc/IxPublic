#ifndef xString_h__
#define xString_h__

#include <iostream>
namespace IOx 
{
	class String
	{
		friend std::ostream& operator<<(std::ostream& out, String& str);
		friend std::istream& operator>>(std::istream& in, String& str);
		friend std::istream& getline(std::istream& in, String& str, char delim);
		friend std::istream& getline(std::istream& in, String& str);
		friend bool operator==(const String& lhs, const String& rhs);
		friend bool operator==(const char* lhs, const String& rhs);
		friend bool operator==(const String& lhs, const char* rhs);
		friend bool operator!=(const String& lhs, const String& rhs);
		friend bool operator!=(const char* lhs, const String& rhs);
		friend bool operator!=(const String& lhs, const char* rhs);
		friend bool operator<(const String& lhs, const String& rhs);
		friend bool operator<(const char* lhs, const String& rhs);
		friend bool operator<(const String& lhs, const char* rhs);
		friend bool operator<=(const String& lhs, const String& rhs);
		friend bool operator<=(const char* lhs, const String& rhs);
		friend bool operator<=(const String& lhs, const char* rhs);
		friend bool operator>(const String& lhs, const String& rhs);
		friend bool operator>(const char* lhs, const String& rhs);
		friend bool operator>(const String& lhs, const char* rhs);
		friend bool operator>=(const String& lhs, const String& rhs);
		friend bool operator>=(const char* lhs, const String& rhs);
		friend bool operator>=(const String& lhs, const char* rhs);
		friend String operator+(const String& lhs, const String& rhs);
		friend String operator+(const String& lhs, const char* rhs);
		friend String operator+(const char* lhs, const String& rhs);
		friend String operator+(const String& lhs, char rhs);
		friend String operator+(char lhs, const String& rhs);

	public:
		String();
		String(const String& str);
		String(const String& str, size_t pos, size_t len);
		String(const char* s);
		String(const char* s, size_t n);
		String(size_t n, char c);
		~String();
		void clear() noexcept;

		char& front() { return at(0); }
		const char& front() const { return at(0); }
		char& back() { return at(ssize - 1); }
		const char& back() const { return at(ssize - 1); }

		const char* c_str() const;
		size_t length() const noexcept;
		size_t size() const noexcept;
		const char* find(const String& w) const;
		const char* fastfind(const String& w);

		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;
		String& operator=(const String& str);
		String& operator=(const char* s);
		String& operator=(char c);
		String& operator+=(const String& str);
		String& operator+=(const char* s);
		String& operator+=(char c);

		String& append(const String& str);
		String& append(const char* s);

		String& assign(const String& str);
		String& assign(const char* s);

		char& at(size_t pos);
		const char& at(size_t pos) const;

		int compare(const String& str) const;
		int compare(const char* s) const;
		void swap(String& str);
		void push_back(char c) { *this += c; }
		const char* data() const;
		bool empty() const;

	private:
		enum
		{
			BUF_LEN = 16
		};

		size_t ssize;
		union _Bxty {
			char _Buf[BUF_LEN];
			char* _ptr;
		} _Bx;

		void rrsize(size_t x);              //À©ÈÝ
		const char* getnext(const char* w); //kmp
	};
}
#endif // xString_h__

