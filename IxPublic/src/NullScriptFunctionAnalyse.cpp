#include "NullScriptFunctionAnalyse.h"
#include <string>
#include <list>
using namespace std;
CNullScriptFunctionAnalyse::CNullScriptFunctionAnalyse(void)
	:m_strValue(nullptr)
{

}


CNullScriptFunctionAnalyse::~CNullScriptFunctionAnalyse(void)
{

}

bool CNullScriptFunctionAnalyse::Load(const char* szScript, int nLen /*= 0*/)
{
	size_t len = strlen(szScript)+1;

	if (!m_strValue)
	{
		delete[] m_strValue;
		m_strValue = nullptr;
	}
	m_strValue = new char[len];
	memset(m_strValue, '\0', sizeof(char) * (len));
	memcpy(m_strValue, szScript, sizeof(char) * (len));
	return true;
}

const char * CNullScriptFunctionAnalyse::Name()
{
	return m_strValue;
}

int CNullScriptFunctionAnalyse::GetParamCount()
{
	return 0;
}

const char* CNullScriptFunctionAnalyse::GetParamType(int nIndex)
{
	return m_strValue;
}

const char* CNullScriptFunctionAnalyse::GetParamValue(int nIndex)
{
	return m_strValue;
}

const char* CNullScriptFunctionAnalyse::CombinationFunction(const char* szFunctionName, void* sListParam)
{
	std::list<std::string>& lstParam = *(std::list<std::string>*)sListParam;
	return m_strValue;
}
