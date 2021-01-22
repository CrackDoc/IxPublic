//////////////////////////////////////////////////////////////////////////
//	@File		:	ScriptAnalyseFactory.h
//	@Data		:	2015-12-22 15:27
//	@Author		:	IDeath
//	@Brief		:	创建脚本解析简单工厂类
//
//////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef ScriptAnalyseFactory_h__
#define ScriptAnalyseFactory_h__
#include "PublicExport.h"

#include "IScriptAnalyzer.h"
#include "IScriptFunctionAnalyse.h"
#include <memory>
#include <string>

/**
*	@brief	所有的脚本解析工厂创建类。
*/
class PUBLIC_EXPORT CScriptAnalyseFactory
{
public:
	/**
	*	@brief	根据在接口定义的UUID，返回真实的执行对象。
	*/
	virtual std::shared_ptr<IScriptAnalyzer> CreateScriptAnalyser(std::string strScriptAnalyzer);

	/**
	* @brief 静态辅助函数，为了方便外面调用。
	*/
	static std::shared_ptr<IScriptFunctionAnalyse> GetFunctionAnalyser(std::string strScriptAnalyzer);
};
#endif // ScriptAnalyseFactory_h__