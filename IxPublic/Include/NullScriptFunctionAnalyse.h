#ifndef NullScriptFunctionAnalyse_h__
#define NullScriptFunctionAnalyse_h__
#include "IScriptFunctionAnalyse.h"

class PUBLIC_EXPORT CNullScriptFunctionAnalyse :public IScriptFunctionAnalyse
{
public:
	CNullScriptFunctionAnalyse(void);
	~CNullScriptFunctionAnalyse(void);
	/**
	*	@brief	解析脚本
	*/
	virtual bool Load(std::string szScript, int nLen = 0);
	
	/**
	*	@brief	返回解析后的函数名称。
	*/
	virtual std::string Name();
	
	/**
	*	@brief	返回解析结果参数数量。
	*/
	virtual int GetParamCount();
	
	/**
	*	@brief	返回某个参数的类型。
	*/
	virtual std::string GetParamType(int nIndex);
	
	/**
	*	@brief	返回某个参数的值。
	*/
	virtual std::string GetParamValue(int nIndex);
	
	/**
	*	@brief	根据输入参数组合成函数。
	*/
	virtual std::string CombinationFunction(std::string szFunctionName, std::list<std::string>& sListParam);

private:
	std::string m_strValue;
};
#endif // NullScriptFunctionAnalyse_h__
