#ifndef xStringList_h__
#define xStringList_h__

namespace IOx
{
	class StringList
	{
	public:
			StringList();

		    StringList(const char **szGroup, size_t nSize);

			StringList(const StringList& other);

			~StringList();

			bool contains(const char * str) const;

			StringList filter(const char * str) const;

			const char* join(const char * separator) const;

			const char* join(char separator) const;

			bool empty();

			size_t size() const;

			void clear();

			void push_back(const char * str);

			void append(const char * str);

			char** data() const;

			const char * at(size_t pos) const;

			const char * front() const { return at(0); }

			const char * back() const { return at(m_nSize - 1); }

			StringList& operator+(const StringList& other);

			StringList& operator<<(const char * str);

			StringList& operator<<(const StringList& other);

			StringList& operator=(const StringList& other);

			const char* operator[](size_t i) const;

	private:
		mutable size_t m_nSize;

		mutable char** m_pBuffer;
	};
}
#endif // xStringList_h__

