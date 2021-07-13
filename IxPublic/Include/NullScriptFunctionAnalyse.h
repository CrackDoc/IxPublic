#ifndef NullScriptFunctionAnalyse_h__
#define NullScriptFunctionAnalyse_h__
#include "IScriptFunctionAnalyse.h"

class IxPublic_EXPORT CNullScriptFunctionAnalyse :public IScriptFunctionAnalyse
{
public:
	CNullScriptFunctionAnalyse(void);
	~CNullScriptFunctionAnalyse(void);
	/**
	*	@brief	解析脚本
	*/
	virtual bool Load(const char * szScript, int nLen = 0);
	
	/**
	*	@brief	返回解析后的函数名称。
	*/
	virtual const char* Name();
	
	/**
	*	@brief	返回解析结果参数数量。
	*/
	virtual int GetParamCount();
	
	/**
	*	@brief	返回某个参数的类型。
	*/
	virtual const char* GetParamType(int nIndex);
	
	/**
	*	@brief	返回某个参数的值。
	*/
	virtual const char* GetParamValue(int nIndex);
	
	/**
	*	@brief	根据输入参数组合成函数。
	*/
	virtual const char* CombinationFunction(const char* szFunctionName, void * sListParam);

private:
	char * m_strValue;
};
#endif // NullScriptFunctionAnalyse_h__
