//////////////////////////////////////////////////////////////////////////
//	@File		:	IScriptFunctionAnalyse.h
//	@Data		:	2015-12-22 15:25
//	@Author		:	IDeath
//	@Brief		:	函数格式脚本分析
//
/*	正确格式：
					QStringList sListData;
					sListData.append("开始1(98(585241.14541), 323(看电视))");
					sListData.append("开始()");
					sListData.append("开始1(开始2,开始3)");
					sListData.append("开始1( 开始2( 都是 ), 开始3(也许))");
					sListData.append("main()");
					sListData.append("main(  )");
					sListData.append(" main (  ) ");
					sListData.append(" _main ( dsdsdwew1, char( dsdsdwew2 ), dsdsdwew3, char  ( dsdsdwew4 ))");
					sListData.append("1main(char, int, jjj)");
					sListData.append("_main(char, int)");
					sListData.append(" _main (char, int)");
					sListData.append(" _main ( char , int )");
					sListData.append(" _main ( char, int(dsdw))");
					sListData.append(" 1main ( char , int(dsdw))");
					sListData.append(" _main ( char, int(dsdw))");
					sListData.append(" _main (1)");
	错误格式：
					sListData.append("开始1(1.3.2)");
					sListData.append("开始1(1.我)");
					sListData.append("开始1(1.)");
					sListData.append("开始1(.3)");
					sListData.append("开始1(., 开始3)");
					sListData.append("开始1(.开始2, .开始3)");
					sListData.append("开始1( 开始2( 都是 ), 开始3(也许(都是)))");
					sListData.append("开始1(开 始3)");
					sListData.append("开始1(开始2， 开始3)");
					sListData.append(" “()");
					sListData.append("】()");
					sListData.append("-(323)");
					sListData.append("~(323)");
					sListData.append("!()");
					sListData.append("@()");
					sListData.append("#()");
					sListData.append("$()");
					sListData.append("%()");
					sListData.append(" * ()");
					sListData.append(" (()");
					sListData.append(" )(232()");
					sListData.append(" >()");
					sListData.append(" <()");
					sListData.append(" /()");
					sListData.append(" ?()");
					sListData.append(" '()");
					sListData.append("  (323  ) ");
					sListData.append(" main, (  ) ");
					sListData.append(" _main (,1)");
					sListData.append("main(dfd char,int)");
					sListData.append("main( sssd char argv )");
					sListData.append(" _main ( (1))");
					sListData.append("dsaewe");
					sListData.append("^dsaewe");
					sListData.append("^dsaewe()");
					sListData.append("dsaewe *7");
					sListData.append("[]");
					sListData.append("ds*()");
					
					if (pAnalyzer->Load(szData))
					{
						qDebug() << szData << "函数名称:" << pAnalyzer->Name();
						int nParamCount = pAnalyzer->GetParamCount();
						for (int i = 0; i < nParamCount; ++i)
						{
							qDebug() << "参数类型: " << pAnalyzer->GetParamType(i) << "  " << "参数值: " << pAnalyzer->GetParamValue(i);
						}
					}
					else
					{
						qDebug() << "分析错误" << szData;
					}
					*/
//////////////////////////////////////////////////////////////////////////
#ifndef IScriptFunctionAnalyse_h__
#define IScriptFunctionAnalyse_h__

#include "IScriptAnalyzer.h"
#include <list>
#include "PublicExport.h"

class PUBLIC_EXPORT IScriptFunctionAnalyse : public IScriptAnalyzer
{
public:
	IScriptFunctionAnalyse(){};
	virtual ~IScriptFunctionAnalyse(){};

	/**
	*	@brief	解析脚本
	*/
	virtual bool Load(const char *szScript, int nLen = 0) = 0;
	
	/**
	*	@brief	返回解析后的函数名称。
	*/
	virtual const char* Name() = 0;
	
	/**
	*	@brief	返回解析结果参数数量。
	*/
	virtual int GetParamCount() = 0;
	
	/**
	*	@brief	返回某个参数的类型。
	*/
	virtual const char* GetParamType(int nIndex) = 0;
	
	/**
	*	@brief	返回某个参数的值。
	*/
	virtual const char* GetParamValue(int nIndex) = 0;
	
	/**
	*	@brief	根据输入参数组合成函数。
	*/
	virtual const char* CombinationFunction(const char* szFunctionName, std::list<const char*>& sListParam) = 0;
};
#endif // IScriptFunctionAnalyse_h__