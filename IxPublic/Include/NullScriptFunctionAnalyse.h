#ifndef NullScriptFunctionAnalyse_h__
#define NullScriptFunctionAnalyse_h__
#include "IScriptFunctionAnalyse.h"

class PUBLIC_EXPORT CNullScriptFunctionAnalyse :public IScriptFunctionAnalyse
{
public:
	CNullScriptFunctionAnalyse(void);
	~CNullScriptFunctionAnalyse(void);
	/**
	*	@brief	�����ű�
	*/
	virtual bool Load(std::string szScript, int nLen = 0);
	
	/**
	*	@brief	���ؽ�����ĺ������ơ�
	*/
	virtual std::string Name();
	
	/**
	*	@brief	���ؽ����������������
	*/
	virtual int GetParamCount();
	
	/**
	*	@brief	����ĳ�����������͡�
	*/
	virtual std::string GetParamType(int nIndex);
	
	/**
	*	@brief	����ĳ��������ֵ��
	*/
	virtual std::string GetParamValue(int nIndex);
	
	/**
	*	@brief	�������������ϳɺ�����
	*/
	virtual std::string CombinationFunction(std::string szFunctionName, std::list<std::string>& sListParam);

private:
	std::string m_strValue;
};
#endif // NullScriptFunctionAnalyse_h__
