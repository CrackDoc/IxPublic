#include "NullScriptFunctionAnalyse.h"


CNullScriptFunctionAnalyse::CNullScriptFunctionAnalyse(void):
	m_strValue(nullptr)
{

}


CNullScriptFunctionAnalyse::~CNullScriptFunctionAnalyse(void)
{

}

bool CNullScriptFunctionAnalyse::Load(const char* szScript, int nLen /*= 0*/)
{
	if(nLen == 0)
	{
		return false;
	}
	if (!m_strValue)
	{
		delete[] m_strValue;
		m_strValue = nullptr;
	}
	m_strValue = new char[nLen];
	memset(m_strValue, '\0', sizeof(char) * nLen);
	memcpy(m_strValue, szScript,sizeof(char)*nLen);

	return true;
}

const char* CNullScriptFunctionAnalyse::Name()
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

const char* CNullScriptFunctionAnalyse::CombinationFunction(const char* szFunctionName, std::list<const char*>& sListParam)
{
	return m_strValue;
}
