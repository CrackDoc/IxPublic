#ifndef NullScriptFunctionAnalyse_h__
#define NullScriptFunctionAnalyse_h__
#include "IScriptFunctionAnalyse.h"

class IxPublic_EXPORT CNullScriptFunctionAnalyse :public IScriptFunctionAnalyse
{
public:
	CNullScriptFunctionAnalyse(void);
	~CNullScriptFunctionAnalyse(void);
	/**
	*	@brief	�����ű�
	*/
	virtual bool Load(const char * szScript, int nLen = 0);
	
	/**
	*	@brief	���ؽ�����ĺ������ơ�
	*/
	virtual const char* Name();
	
	/**
	*	@brief	���ؽ����������������
	*/
	virtual int GetParamCount();
	
	/**
	*	@brief	����ĳ�����������͡�
	*/
	virtual const char* GetParamType(int nIndex);
	
	/**
	*	@brief	����ĳ��������ֵ��
	*/
	virtual const char* GetParamValue(int nIndex);
	
	/**
	*	@brief	�������������ϳɺ�����
	*/
	virtual const char* CombinationFunction(const char* szFunctionName, void * sListParam);

private:
	char * m_strValue;
};
#endif // NullScriptFunctionAnalyse_h__
