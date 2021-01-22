//////////////////////////////////////////////////////////////////////////
//	@File		:	ScriptAnalyseFactory.h
//	@Data		:	2015-12-22 15:27
//	@Author		:	IDeath
//	@Brief		:	�����ű������򵥹�����
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
*	@brief	���еĽű��������������ࡣ
*/
class PUBLIC_EXPORT CScriptAnalyseFactory
{
public:
	/**
	*	@brief	�����ڽӿڶ����UUID��������ʵ��ִ�ж���
	*/
	virtual std::shared_ptr<IScriptAnalyzer> CreateScriptAnalyser(std::string strScriptAnalyzer);

	/**
	* @brief ��̬����������Ϊ�˷���������á�
	*/
	static std::shared_ptr<IScriptFunctionAnalyse> GetFunctionAnalyser(std::string strScriptAnalyzer);
};
#endif // ScriptAnalyseFactory_h__