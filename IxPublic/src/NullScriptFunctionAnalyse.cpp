#include "NullScriptFunctionAnalyse.h"


CNullScriptFunctionAnalyse::CNullScriptFunctionAnalyse(void)
{

}


CNullScriptFunctionAnalyse::~CNullScriptFunctionAnalyse(void)
{

}

bool CNullScriptFunctionAnalyse::Load(std::string szScript, int nLen /*= 0*/)
{
	m_strValue = szScript;
	return true;
}

std::string CNullScriptFunctionAnalyse::Name()
{
	return m_strValue;
}

int CNullScriptFunctionAnalyse::GetParamCount()
{
	return 0;
}

std::string CNullScriptFunctionAnalyse::GetParamType(int nIndex)
{
	return m_strValue;
}

std::string CNullScriptFunctionAnalyse::GetParamValue(int nIndex)
{
	return m_strValue;
}

std::string CNullScriptFunctionAnalyse::CombinationFunction(std::string szFunctionName, std::list<std::string>& sListParam)
{
	return m_strValue;
}
