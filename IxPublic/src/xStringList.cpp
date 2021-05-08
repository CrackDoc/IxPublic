#include "xStringList.h"
#include <string>
#include <sstream>
#include "assert.h" 

namespace IOx
{
	StringList::StringList()
		:m_nSize(0)
		, m_pBuffer(nullptr)
	{

	}

	StringList::StringList(const char** szGroup, size_t nSize)
		: m_nSize(0)
		, m_pBuffer(nullptr)
	{
		if (m_pBuffer && m_nSize != 0)
		{
			for (size_t i = 0; i < m_nSize; ++i)
			{
				char* pBuffer = m_pBuffer[i];
				assert(pBuffer);
				if (pBuffer)
				{
					delete[] pBuffer;
					pBuffer = nullptr;
				}
			}
			delete[] m_pBuffer;
			m_pBuffer = nullptr;
		}

		m_nSize = nSize;

		m_pBuffer = (char**)new char[m_nSize];

		for (size_t i = 0; i < m_nSize; ++i)
		{
			char* pBuffer = (char*)(&szGroup+i);
			assert(pBuffer);
			size_t nLen = strlen(pBuffer)+1;
			char* pCopyBuffer = new char[nLen];
			assert(pCopyBuffer);
			memset(pCopyBuffer, '\0', sizeof(char) * nLen);
			memcpy(pCopyBuffer, pBuffer, sizeof(char) * nLen);
			m_pBuffer[i] = pCopyBuffer;
		}
	}

	StringList::StringList(const StringList& other)
	{
		char** szGroup = other.data();
		size_t nSize = other.size();

		if (m_pBuffer && m_nSize != 0)
		{
			for (size_t i = 0; i < m_nSize; ++i)
			{
				char* pBuffer = m_pBuffer[i];
				assert(pBuffer);
				if (pBuffer)
				{
					delete[] pBuffer;
					pBuffer = nullptr;
				}
			}
			delete[] m_pBuffer;
			m_pBuffer = nullptr;
		}

		m_nSize = nSize;

		m_pBuffer = (char**)new char[m_nSize];

		for (size_t i = 0; i < m_nSize; ++i)
		{
			char* pBuffer = (char*)(&szGroup + i);
			assert(pBuffer);
			size_t nLen = strlen(pBuffer) + 1;
			char* pCopyBuffer = new char[nLen];
			assert(pCopyBuffer);
			memset(pCopyBuffer, '\0', sizeof(char) * nLen);
			memcpy(pCopyBuffer, pBuffer, sizeof(char) * nLen);
			m_pBuffer[i] = pCopyBuffer;
		}
	}

	StringList::~StringList()
	{
		if (m_pBuffer && m_nSize != 0)
		{
			for (size_t i = 0; i < m_nSize; ++i)
			{
				char* pBuffer = m_pBuffer[i];
				assert(pBuffer);
				if (pBuffer)
				{
					delete[] pBuffer;
					pBuffer = nullptr;
				}
			}
			delete[] m_pBuffer;
			m_pBuffer = nullptr;
		}
		m_nSize = 0;
	}

	bool StringList::contains(const char * str) const
	{
		// 查找相应的字符串
		if (!m_pBuffer)
		{
			return false;
		}
		for (size_t i = 0; i < size(); ++i)
		{
			if (strcmp(str, m_pBuffer[i]) == 0)
			{
				return true;
			}
		}
		return false;
	}

	StringList StringList::filter(const char * str) const
	{ 
		// 查找相应的字符串
		StringList strList;

		if (!m_pBuffer)
		{
			return StringList();
		}

		for (size_t i = 0; i < size(); ++i)
		{
			char* pBuffer = (char*)m_pBuffer[i];

			char* pch = nullptr;

			pch = strstr(pBuffer, str);

			size_t nstrLen = strlen(str);

			while (pch)
			{
				size_t nValue = pch - str + 1;

				memmove(pBuffer + nValue, str, nstrLen);

				pch = strstr(pBuffer, str);
			}
			strList.append(pBuffer);

		}
		return strList;

	}

	const char* StringList::join(const char * separator) const
	{
		if (!m_pBuffer || m_nSize == 0)
		{
			return "";
		}
		std::stringstream ss;
		for (size_t i = 0; i < size(); ++i)
		{
			ss << m_pBuffer[i];
			if (i != (size_t)size() - 1)
			{
				ss << separator;
			}
		}

		return ss.str().c_str();
	}

	const char* StringList::join(char separator) const
	{
		if (!m_pBuffer || m_nSize == 0)
		{
			return "";
		}
		std::stringstream ss;
		for (size_t i = 0; i < size(); ++i)
		{
			ss << m_pBuffer[i];
			if (i != (size_t)size() - 1)
			{
				ss << separator;
			}
		}
		return ss.str().c_str();
	}

	bool StringList::empty()
	{
		return m_pBuffer;
	}

	size_t StringList::size() const
	{
		return m_nSize;
	}

	void StringList::clear()
	{
		if (m_nSize == 0)
		{
			return;
		}
		for (size_t i = 0; i < m_nSize; ++i)
		{
			char* pBuffer = (char*)(&m_pBuffer + i);
			assert(pBuffer);
			size_t nLen = strlen(pBuffer) + 1;
			memset(pBuffer, '\0', sizeof(char) * nLen);
		}
	}

	void StringList::push_back(const char * str)
	{
		m_pBuffer = (char**)realloc(m_pBuffer,sizeof(char));
		assert(m_pBuffer);
		m_nSize += 1;

		size_t nLen = strlen(str) + 1;

		char* pCopyBuffer = new char[nLen];
		assert(pCopyBuffer);
		memset(pCopyBuffer, '\0', sizeof(char) * nLen);
		memcpy(pCopyBuffer, str, sizeof(char) * nLen);
		m_pBuffer[m_nSize-1] = pCopyBuffer;

	}

	void StringList::append(const char * str)
	{
		push_back(str);

	}

	char** StringList::data() const
	{
		return m_pBuffer;
	}
	const char * StringList::at(size_t pos) const
	{
		if (pos > m_nSize - 1)
		{
			return nullptr;
		}
		if (m_pBuffer && m_nSize != 0)
		{
			return m_pBuffer[pos];
		}
		return nullptr;
	}

	StringList&  StringList::operator+(const StringList& other)
	{
		m_pBuffer = (char**)realloc(m_pBuffer, sizeof(char)*other.size());
		assert(m_pBuffer);
		
		for (size_t i = 0; i < other.size(); ++i)
		{
			push_back(other.at(i));
		}
		return *this;
	}

	StringList& StringList::operator<<(const char * str)
	{
		push_back(str);
		return *this;
	}

	StringList& StringList::operator<<(const StringList& other)
	{
		for (size_t i = 0; i < other.size(); ++i)
		{
			push_back(other.at(i));
		}
		return *this;

	}

	const char* StringList::operator[](size_t i) const
	{
		return at(i);
	}

	StringList& StringList::operator=(const StringList& other)
	{
		char** szGroup = other.data();
		size_t nSize = other.size();

		if (m_pBuffer && m_nSize != 0)
		{
			for (size_t i = 0; i < m_nSize; ++i)
			{
				char* pBuffer = m_pBuffer[i];
				assert(pBuffer);
				if (pBuffer)
				{
					delete[] pBuffer;
					pBuffer = nullptr;
				}
			}
			delete[] m_pBuffer;
			m_pBuffer = nullptr;
		}

		m_nSize = nSize;

		m_pBuffer = (char**)new char[m_nSize];

		for (size_t i = 0; i < m_nSize; ++i)
		{
			char* pBuffer = (char*)(&szGroup + i);
			assert(pBuffer);
			size_t nLen = strlen(pBuffer) + 1;
			char* pCopyBuffer = new char[nLen];
			assert(pCopyBuffer);
			memset(pCopyBuffer, '\0', sizeof(char) * nLen);
			memcpy(pCopyBuffer, pBuffer, sizeof(char) * nLen);
			m_pBuffer[i] = pCopyBuffer;
		}
		return *this;

	}

}

